#!/usr/bin/env python3
"""
Assemble the hand-written lab1 tests (.asm -> .mem).

These programs use only the instruction set this lab implements, so they need no
RISC-V toolchain -- unlike the compiled tests in test/takehome, which are built
from .S by test/Makefile with riscv32-unknown-elf-gcc.

Usage, from the lab1/ directory:

    python3 test/asm2mem.py test/inclass_1     # rebuild a whole directory
    python3 test/asm2mem.py test/inclass_2/test4.asm  # rebuild one file
    python3 test/asm2mem.py                    # rebuild inclass_* + takehome

Output format: one 8-digit hex word per line, word i holding byte address 4*i.
The processor resets to `STARTPC = 0x200, which is word index 128, so the first
128 words are padding.  Every program must end with `.halt`, a 0x00000000 word:
that decodes to `INVALID_I, which sim_main.cpp treats as "end of program".

Supported: addi add sub and or xor andi ori xori sll srl sra slli srli srai
slt sltu slti sltiu lui auipc jal jalr lw sw beq bne blt bge bltu bgeu,
plus labels, `.halt` and `.word <value>`.
"""

import os
import re
import sys

STARTPC = 0x200
START_WORD = STARTPC // 4

# Register-file initialisation words the original tests carried at address 0.
# Never executed -- the PC starts at 0x200 -- but kept so the memory image
# matches the older tests in the region before the program.
PREAMBLE = [
    0x00000100, 0x00000113, 0x00000193, 0x00000213,
    0x00000293, 0x00000313, 0x00000393, 0x00000413,
]

ABI = {
    "zero": 0, "ra": 1, "sp": 2, "gp": 3, "tp": 4,
    "t0": 5, "t1": 6, "t2": 7,
    "s0": 8, "fp": 8, "s1": 9,
    "a0": 10, "a1": 11, "a2": 12, "a3": 13,
    "a4": 14, "a5": 15, "a6": 16, "a7": 17,
    "s2": 18, "s3": 19, "s4": 20, "s5": 21, "s6": 22,
    "s7": 23, "s8": 24, "s9": 25, "s10": 26, "s11": 27,
    "t3": 28, "t4": 29, "t5": 30, "t6": 31,
}

OP_IMM, OP_REG, OP_BRANCH = 0b0010011, 0b0110011, 0b1100011
OP_LOAD, OP_STORE = 0b0000011, 0b0100011
OP_LUI, OP_AUIPC = 0b0110111, 0b0010111
OP_JAL, OP_JALR = 0b1101111, 0b1100111

# mnemonic -> (funct3, funct7)
RR = {"add": (0b000, 0), "sub": (0b000, 0x20), "and": (0b111, 0), "or": (0b110, 0),
      "xor": (0b100, 0), "sll": (0b001, 0), "srl": (0b101, 0), "sra": (0b101, 0x20),
      "slt": (0b010, 0), "sltu": (0b011, 0), "mul": (0b000, 0x01)}
RI = {"addi": 0b000, "andi": 0b111, "ori": 0b110, "xori": 0b100,
      "slti": 0b010, "sltiu": 0b011}
SH = {"slli": (0b001, 0), "srli": (0b101, 0), "srai": (0b101, 0x20)}
BR = {"beq": 0b000, "bne": 0b001, "blt": 0b100,
      "bge": 0b101, "bltu": 0b110, "bgeu": 0b111}


class AsmError(Exception):
    pass


def reg(tok):
    tok = tok.strip().lower()
    if tok in ABI:
        return ABI[tok]
    m = re.fullmatch(r"x(\d+)", tok)
    if m and 0 <= int(m.group(1)) < 32:
        return int(m.group(1))
    raise AsmError("not a register: %r" % tok)


def imm(tok, lo, hi):
    v = int(tok, 0)
    if not lo <= v <= hi:
        raise AsmError("immediate %d out of range [%d, %d]" % (v, lo, hi))
    return v


def mem_operand(args):
    """Parse `offset(base)` -- possibly already split on commas/spaces."""
    text = "".join(args)
    m = re.fullmatch(r"(-?\w+)\((\w+)\)", text)
    if not m:
        raise AsmError("expected offset(base), got %r" % text)
    return int(m.group(1), 0), reg(m.group(2))


def enc_i(f3, rd, rs1, i):
    return ((i & 0xFFF) << 20) | (rs1 << 15) | (f3 << 12) | (rd << 7) | OP_IMM


def enc_r(f3, f7, rd, rs1, rs2):
    return (f7 << 25) | (rs2 << 20) | (rs1 << 15) | (f3 << 12) | (rd << 7) | OP_REG


def enc_b(f3, rs1, rs2, off):
    if off % 2:
        raise AsmError("branch offset must be even: %d" % off)
    if not -4096 <= off <= 4094:
        raise AsmError("branch offset out of range: %d" % off)
    o = off & 0x1FFF
    return (((o >> 12) & 1) << 31) | (((o >> 5) & 0x3F) << 25) | \
           (rs2 << 20) | (rs1 << 15) | (f3 << 12) | \
           (((o >> 1) & 0xF) << 8) | (((o >> 11) & 1) << 7) | OP_BRANCH


def enc_j(rd, off):
    if off % 2:
        raise AsmError("jal offset must be even: %d" % off)
    if not -(1 << 20) <= off < (1 << 20):
        raise AsmError("jal offset out of range: %d" % off)
    o = off & 0x1FFFFF
    return (((o >> 20) & 1) << 31) | (((o >> 1) & 0x3FF) << 21) | \
           (((o >> 11) & 1) << 20) | (((o >> 12) & 0xFF) << 12) | \
           (rd << 7) | OP_JAL


def encode(mnem, args, pc, labels):
    def target(tok):
        return labels[tok] if tok in labels else int(tok, 0)

    if mnem == ".halt":
        return 0x00000000
    if mnem == ".word":
        return int(args[0], 0) & 0xFFFFFFFF
    if mnem in RR:
        f3, f7 = RR[mnem]
        return enc_r(f3, f7, reg(args[0]), reg(args[1]), reg(args[2]))
    if mnem in RI:
        return enc_i(RI[mnem], reg(args[0]), reg(args[1]), imm(args[2], -2048, 2047))
    if mnem in SH:
        f3, f7 = SH[mnem]
        sh = imm(args[2], 0, 31)
        return enc_i(f3, reg(args[0]), reg(args[1]), (f7 << 5) | sh)
    if mnem in BR:
        return enc_b(BR[mnem], reg(args[0]), reg(args[1]), target(args[2]) - pc)
    if mnem in ("lui", "auipc"):
        op = OP_LUI if mnem == "lui" else OP_AUIPC
        return ((imm(args[1], 0, 0xFFFFF) & 0xFFFFF) << 12) | (reg(args[0]) << 7) | op
    if mnem == "jal":
        # jal rd, label   or   jal label  (rd defaults to ra)
        if len(args) == 1:
            return enc_j(1, target(args[0]) - pc)
        return enc_j(reg(args[0]), target(args[1]) - pc)
    if mnem == "jalr":
        # jalr rd, rs1, imm   or   jalr rd, imm(rs1)
        if len(args) == 3:
            return ((imm(args[2], -2048, 2047) & 0xFFF) << 20) | \
                   (reg(args[1]) << 15) | (reg(args[0]) << 7) | OP_JALR
        off, base = mem_operand(args[1:])
        return ((off & 0xFFF) << 20) | (base << 15) | (reg(args[0]) << 7) | OP_JALR
    if mnem == "lw":
        off, base = mem_operand(args[1:])
        return ((off & 0xFFF) << 20) | (base << 15) | (0b010 << 12) | \
               (reg(args[0]) << 7) | OP_LOAD
    if mnem == "sw":
        off, base = mem_operand(args[1:])
        src = reg(args[0])
        return (((off >> 5) & 0x7F) << 25) | (src << 20) | (base << 15) | \
               (0b010 << 12) | ((off & 0x1F) << 7) | OP_STORE
    raise AsmError("unsupported instruction %r" % mnem)


def assemble(path):
    lines = []
    for n, raw in enumerate(open(path), 1):
        text = raw.split("#")[0].strip()
        if text:
            lines.append((n, text))

    labels, body, pc = {}, [], STARTPC
    for n, text in lines:
        while ":" in text:
            label, _, text = text.partition(":")
            labels[label.strip()] = pc
            text = text.strip()
        if text:
            body.append((n, pc, text))
            pc += 4

    words = []
    for n, pc, text in body:
        parts = [p for p in re.split(r"[\s,]+", text) if p]
        try:
            words.append(encode(parts[0].lower(), parts[1:], pc, labels))
        except AsmError as e:
            raise AsmError("%s:%d: %s" % (path, n, e))
        except (KeyError, IndexError, ValueError) as e:
            raise AsmError("%s:%d: could not assemble %r (%s)" % (path, n, text, e))

    if not words or words[-1] != 0:
        raise AsmError("%s: program does not end with .halt" % path)
    return words


def write_mem(path, words):
    image = list(PREAMBLE) + [0] * (START_WORD - len(PREAMBLE)) + words
    with open(path, "w", newline="\n") as f:
        for w in image:
            f.write("%08x\n" % (w & 0xFFFFFFFF))


def build(src):
    dst = src[:-4] + ".mem"
    write_mem(dst, assemble(src))
    print("%s -> %s" % (src, os.path.basename(dst)))


def main(argv):
    here = os.path.dirname(os.path.abspath(__file__))
    targets = argv[1:] or [os.path.join(here, "inclass_1"),
                           os.path.join(here, "inclass_2"),
                           os.path.join(here, "takehome"),
                           os.path.join(here, "bonus")]
    for t in targets:
        if not os.path.isdir(t):
            build(t)          # named explicitly: any error is fatal
            continue
        # Scanning a directory.  Some .asm files next to the compiled tests are
        # listings that belong to gcc, not sources for this script, so skip
        # anything with a sibling .S and anything this script cannot parse.
        for name in sorted(os.listdir(t)):
            if not name.endswith(".asm"):
                continue
            src = os.path.join(t, name)
            if os.path.exists(src[:-4] + ".S"):
                print("%s -- skipped, built from .S by test/Makefile" % src)
                continue
            try:
                build(src)
            except AsmError as e:
                print("%s -- skipped, not in asm2mem syntax (%s)" % (src, e))


if __name__ == "__main__":
    try:
        main(sys.argv)
    except AsmError as e:
        sys.exit("error: %s" % e)
