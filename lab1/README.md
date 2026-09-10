# CS 3220 Lab 1 — A 5-stage RISC-V pipeline

You build a five-stage pipelined processor for a subset of RISC-V (the Tiny
RISC-V variant from Cornell, described in [tinyrv-isa.txt](tinyrv-isa.txt)).

| Part | Covers | Tasks | Points |
|---|---|---|---|
| In-Class 1 | latch plumbing and the ALU | 1–3 | 6 |
| In-Class 2 | branch condition, branch target, redirect | 4–5 | 10 |
| Take-Home  | the rest of the required instruction set | 6–7 | 84 |
| Bonus (optional) | the remaining instructions, `lw` and `sw` | 8 | +10 |

That is 100 points for the required work, plus up to 10 bonus points on top.
Partial credit on each part is the percentage of that part's test cases your
processor passes. Run the suites before you submit and hand in whatever passes.

Every piece of code you have to write is marked in the
source with a numbered `Task`.

---

## Setting up

Follow this [document](https://github.com/gt-cs3220-2026/cs3220-labs-fall2026/blob/main/lab0/Take_home/ICE_environment_setup.pdf) to access OnDemand ICE and connect to Coder to setup experiment environment. 

Remember to run `source /storage/ice-shared/cs3220/labs_setup.sh` and `module load perl/5.36.0` in your terminal to get an environment with
`verilator`, `make`, `g++`. 

---

## What you have to build

The four parts are cumulative: each one runs the earlier suites' instructions as
well, so re-run the earlier suites after every change. The commands quoted below
are explained in [Running things](#running-things), and the file-by-file
breakdown is in [What is in here](#what-is-in-here).

### In-Class 1 — Tasks 1–3, `agex_stage.v`

**Goal:** `./run_tests.sh inclass_1` reports 3 of 3. Those three tests use only
`add` and `addi`, so no branches are needed yet.

AGEX is empty in the skeleton: fetch and decode already work, but nothing
computes a result or hands one to MEM. You supply the three pieces:
**Task 1** unpacks the incoming DE latch, **Task 2** is the ALU, **Task 3** packs
the outgoing AGEX latch.

The thing to understand before you type is how a pipeline latch works here.
Verilog-2001 has no structs, so a stage packs its whole output into one wide
vector and the receiver unpacks it with a concatenation on the left of an
`assign`. Two consequences:

- **Order is the interface.** Only position connects a field to the wire that
  reads it; names do nothing. Verilator catches a wrong total *width*, but a
  wrong *order* compiles cleanly and produces garbage.
- **The receiving stage is the specification.** `de_stage.v` already packs the
  DE latch and `mem_stage.v` already unpacks the AGEX latch, both in files you
  are not editing, so each layout has exactly one correct answer and it is
  already written down somewhere.

For the ALU, note that `op_I_AGEX` decides two things at once: which operands
are used and which operation is applied, which is why one `case` does the whole
job. A combinational block must assign its output on every path or Verilog
infers a latch, so keep a `default`.

**Symptom to recognise:** the design builds and runs, but printed `PC=` values
are wrong or `wregno` names a register the program never mentions. That is a
misaligned concatenation, not an arithmetic bug. Fix the layout first.

### In-Class 2 — Tasks 4–5, `agex_stage.v`

**Goal:** `./run_tests.sh inclass_2` reports 5 of 5, with `inclass_1` still at
3 of 3. This adds the six conditional branches.

**Task 4** computes the branch condition, **Task 5** computes the branch target
and sends the redirect to FE and DE.

FE has no branch predictor: it fetches `PC + 4` every cycle, which amounts to
predicting that no branch is ever taken. AGEX is the first stage that knows the
real answer, so AGEX detects the bad prediction and repairs it. This line is
given to you and **you may not change it**:

```verilog
assign br_mispred_AGEX = (is_br_AGEX && (br_target_AGEX != pcplus_AGEX)) ? 1 : 0;
```

It defines "wrong" as *the target differing from what FE
actually fetched next*, not as "the branch was taken". So `br_target_AGEX` needs
a sensible value on **every** path: taken, not taken, and not-a-branch.

The repair itself is already built. `fe_stage.v` overrides the PC and clears its
latch on a mispredict; `de_stage.v` ORs the same signal into
`pipeline_stall_DE`, which zeroes the DE latch. Your job is only to compute the
target and deliver it. The two output bundles must match the order each
receiving stage unpacks, and their totals must match the `from_AGEX_to_*_WIDTH`
constants.

Two things to keep straight: `is_br_AGEX` ("is this a branch?") is decoded for
you in DE, while `br_cond_AGEX` ("if it is, is the condition true?") is yours.

### Take-Home — Tasks 6–7, `de_stage.v` and `agex_stage.v`

**Goal:** `./run_tests.sh takehome` reports 12 of 12. This adds `sub`, `lui`,
`auipc`, `jal` and `jalr`, together with the immediate formats and decode
signals they need.

**Task 6** (`de_stage.v`) completes the decode: the missing immediate forms, the
two jumps in `is_br_DE`, and the full list of register-writing instructions in
`wr_reg_DE`. **Task 7** (`agex_stage.v`) extends the two blocks you already
wrote: more arms in the ALU `case`, and jump targets in the Task 5 block.

A jump both writes a register *and* redirects the front end, so `jal` and
`jalr` each appear twice in your code: once in the ALU `case`, where the
"result" is the return address, and once in the target block. The two differ
only in where the target comes from.

**Write Tasks 6 and 7 in one sitting before you run the suite.** The compiled
tests are each a chain of small cases, and the chain itself is built out of `li`
(which the assembler turns into `lui` + `addi`), `bne`, and `j` (which is `jal`).
That means none of them pass until `lui`, `bne` and `jal` all work, whatever the
file is named after — `add.mem` is not a test of `add` in isolation. Get the
hand-written `test9` and `test10` (the shortest `jal` and `jalr` tests) passing
first, then run the whole suite and let the list of failures tell you what is
wrong.

### Bonus — Task 8, four files (optional)

**Goal:** `./run_tests.sh bonus`. 

**The easy half** stays in the `agex_stage.v` ALU `case` you have been extending
since Task 2: the logic instructions, the shifts, the set-less-than family, and
`mul`. `test14` is a hand-written spot check of five of
them and stops at the first one that is wrong, so start there. `testall.mem`
runs every arithmetic, logic, shift and compare instruction in one program. Passing the individual tests but failing that one means the bug only appears
when different kinds of instruction run back to back.

**The challenging half** is `lw` and `sw`. Four files have to be changed:

- `agex_stage.v` — where the address is computed, and where it is decided what
  this instruction does to memory, if anything.
- `mem_stage.v` — owns `dmem`. The read and the write are both already written
  for you, so look at what they depend on that never arrives.
- `wb_stage.v` — the value written back can now come from two places, so
  something has to choose.
- `define.vh` — the latch widths.

Work out for yourself which signals must cross which latch. Adding one field to
a latch is always the same four edits at once: compute it, pack it, unpack it at
the *same position*, and count it in the width in `define.vh`. Verilator stops
you if the widths disagree; it cannot see a wrong position, which builds fine and
scrambles the values. `test15` is the smallest `lw`/`sw` test; `lw.mem` and
`sw.mem` are the compiled ones.

---

## Running things

Everything is run from the `lab1/` directory.

```sh
make                    # build the simulator, run the test named in define.vh, and write trace.vcd (waveform)
make clean              # delete obj_dir, the logs and trace.vcd
```

**Running one specific test** — either edit `` `IDMEMINITFILE `` in
[define.vh](define.vh) (it holds a path relative to `lab1/`), or override it on
the command line without touching the file:

```sh
IDMEMINITFILE=$PWD/test/inclass_2/test4.mem make tests
```

The override is passed to Verilator as `+define+`; `define.vh` guards its own
`` `define `` with `` `ifndef ``, so the command line wins and your file is left
alone. Note that imem and dmem are loaded from the *same* file.

**Running a whole suite:**

```sh
./run_tests.sh inclass_1    # the 3 In-Class 1 tests
./run_tests.sh inclass_2    # the 5 In-Class 2 tests
./run_tests.sh takehome     # the 12 take-home tests
./run_tests.sh bonus        # the 32 optional ones
./run_tests.sh all
```

Each leaves `<suite>_tests.log` (the full console output) and
`<suite>_results.log` (one line per test), and prints the names of any tests
that failed.

**Reading the output.** A run prints one line per instruction that reaches
write-back:

```
[28]  PC=0x200 Inst=0x100193 Op=12 wr_reg=1 wregno=3 regval=1
-- stopped at PC=0x204 (end of program) --
Total instructions=1, cycles=9, IPC=0.111111
Passed!
```

`Op` is the internal opcode number from `define.vh` (12 is `` `ADDI_I ``).
Every test program ends with a `0x00000000` word, which decodes to
`` `INVALID_I ``; the simulator stops on the first one that retires. A test passes when it leaves 1 in `gp` (`x3`); otherwise
you get `Failed. exitcode: N`, where `N` is whatever `gp` ended up holding. Each
in-class test writes a different value to `gp` on each wrong path, so read the
`.asm` alongside `N` and it tells you which path the processor took.

**Viewing the wave form.** Follow the instructions in the same [document](https://github.com/gt-cs3220-2026/cs3220-labs-fall2026/blob/main/lab0/Take_home/ICE_environment_setup.pdf) to open Signal Viewer to view the waveform for debugging (remember to install the extension: impulse).

**Building a submission:**

```sh
make submit             # writes submission.zip
```

Use this and **DO NOT zip by hand**.

---

## What is in here

### The processor

Five stages, one module each, wired together in `pipeline.v`. Stages talk to
each other only through packed latch vectors whose widths live in `define.vh`.

| File | What it is | Do you edit it? |
|---|---|---|
| `pipeline.v`  | instantiates the five stages and wires them together | no |
| `fe_stage.v`  | fetch: PC latch, instruction memory, redirect on mispredict | no |
| `de_stage.v`  | decode: opcode decode, register file, immediate, hazard scoreboard | Task 6
| `agex_stage.v`| execute: ALU, branch condition, branch target | Tasks 1–5, 7, 8 |
| `mem_stage.v` | data memory | Task 8 (bonus) |
| `wb_stage.v`  | write-back, and the counters the simulator prints from | Task 8 (bonus) |
| `define.vh`   | every constant: opcode numbers, latch widths, the test file path | Task 8 (bonus) |
| `sim_main.cpp`| the C++ testbench Verilator links against | no |
| `Makefile`, `run_tests.sh` | build and test drivers | no |

Most of your work is in `agex_stage.v`. Read `fe_stage.v`, `de_stage.v`,
`mem_stage.v` and `wb_stage.v` anyway.  They are the specification for the
latches you have to build.

### The tests

| Directory | Suite name | What |
|---|---|---|
| `test/inclass_1/` | `inclass_1` | 3 short programs |
| `test/inclass_2/` | `inclass_2` | 5 short programs |
| `test/takehome/` | `takehome` | 12 programs |
| `test/bonus/`    | `bonus`    | 32 programs, optional |

**`test/inclass_1/`** and **`test/inclass_2/`** are short hand-written programs.
Each `.mem` has its `.asm` next to it, and the `readme.txt` in each directory
says what every test covers.

**`test/takehome/`** and **`test/bonus/`** are mostly the real RISC-V test-suite
programs, compiled. The exceptions are `test9`–`test13` (take-home) and
`test14`–`test16` (bonus), which are hand-written assembly and much easier to
debug — start with those. Each compiled test comes as four files:

- `*.S` is assembly using RISC-V macros, defined in
  [test/include/test_macros.h](test/include/test_macros.h) and
  [test/include/riscv_test.h](test/include/riscv_test.h). It also uses ABI names
  and pseudo-instructions — the manual linked under References summarises both.
- `*.dump` is the disassembly produced by the RISC-V gcc compiler. This is the
  file to read when you want to know what actually executes.
- `*.mem` is the memory image the simulator loads.
- `*.dec` is useful with the RISC-V emulator linked under References.

When a compiled test fails, read the log before the waveform: the last `PC=`
line printed is the last instruction that retired, and finding that address in
the `.dump` usually tells you which instruction is wrong.
`python3 test/dumptoasm.py <name>.dump` pulls plain assembly out of a dump.

---

## What to hand in

Submit **`submission.zip`**, produced by `make submit` to Gradescope.

---

## References

- [RISC-V RV32I manual](https://web.eecs.utk.edu/~smarz1/courses/ece356/notes/assembly/)
  — also covers ABI register names and pseudo-instructions, which you need to
  read the take-home tests
- [RISC-V instruction card](https://github.com/jameslzhu/riscv-card/releases/download/latest/riscv-card.pdf)
  — one page, has every encoding
- [RISC-V emulator (Tiny RV2)](https://www.cs.cornell.edu/courses/cs3410/2019sp/riscv/interpreter/)
  — run a program by hand when you are not sure what the right answer is
- [Verilator manual](https://verilator.org/guide/latest/)
- [Signal Viewer setup (impulse extension)](https://github.com/gt-cs3220-2026/cs3220-labs-fall2026/blob/main/lab0/Take_home/ICE_environment_setup.pdf)
  — how to open `trace.vcd` in Coder
- [Tutorial on the RISC-V test suite](https://web.archive.org/web/20221031194615/https://inst.eecs.berkeley.edu/~cs250/fa10/handouts/tut3-riscv.pdf)

---

## FAQ

**1. My build fails with `%Error: Exiting due to N warning(s)`.**

Verilator treats warnings as errors here, on purpose. A `WIDTHTRUNC` or
`WIDTHEXPAND` on an `assign` means a concatenation does not add up to the latch
width it is assigned to or from — count the fields against `define.vh`. This is
the one class of latch mistake the tool can catch for you; it cannot check the
*order* of the fields, so a wrong order builds cleanly and produces garbage.

**2. A test prints `Total instructions=0`, or nothing at all.**

Nothing reached write-back. Either the memory image did not load — check the
path in `` `IDMEMINITFILE `` — or `valid` is not making it down the latches.

**3. Debugging is taking forever. Any advice?**

1. Read the error message. Verilator's messages name the file, the line and the
   two widths involved.
2. Work out what the program *should* do first, from the `.asm` or `.dump`, or
   by running it in the RISC-V emulator linked above.
3. Then open `trace.vcd` in Signal Viewer. Always put `clk`, `reset` and the `PC_*`
   signals in the trace alongside whatever you are actually investigating.
4. Follow one instruction, not one cycle: every latch carries `inst_count_*`,
   assigned in FE and passed down unchanged.

**4. A branch is taken. Is the new PC `PC + imm` or `PC + 4 + imm`?**

`PC + imm`. Be careful converting the immediate field into an offset.

**5. Why do we drop the low 2 bits of an address?**

The ISA is byte-addressed but `imem`/`dmem` are declared as arrays of 32-bit
words, and this lab has no unaligned accesses, so bits [1:0] are always zero.
The framework already does this for you:
```verilog
assign inst_FE = imem[PC_FE_latch[`IMEMADDRBITS-1:`IMEMWORDBITS]];
dmem[memaddr_MEM[`DMEMADDRBITS-1:`DMEMWORDBITS]];
```
`imem` and `dmem` hold 2^14 words, so only address bits [15:2] are used.

**6. Do I have to stop writes to `x0`?**

No. Keeping `x0` at zero is the assembler's and the programmer's problem, not
the hardware's.

**7. Do I need a branch predictor, or a stack for nested `jal`s?**

No to both. Branches are predicted not-taken; nested calls are software's
problem.

**8. How do I use `signed` in Verilog?**

Verilog treats plain vectors as unsigned. `$signed()` reinterprets the same bits
as two's complement, and so does declaring a `wire signed` copy:
```verilog
wire signed [`DBITS-1:0] s_regval1_AGEX;
wire signed [`DBITS-1:0] s_regval2_AGEX;
assign s_regval1_AGEX = regval1_AGEX;
assign s_regval2_AGEX = regval2_AGEX;

assign s_less = (s_regval1_AGEX < s_regval2_AGEX);  // signed
assign less   = (  regval1_AGEX <   regval2_AGEX);  // unsigned
```
Nothing is converted; the bits are identical. Only the interpretation changes.
Take `regval1 = 0x00000000` and `regval2 = 0xFFFFFFFF`:

| | reads `regval2` as | `regval1 < regval2` |
|---|---|---|
| `less` (unsigned) | 4294967295 | **true** |
| `s_less` (signed) | −1 | **false** |

`blt`/`bge`/`slt`/`slti` want the signed row; `bltu`/`bgeu`/`sltu`/`sltiu` want
the unsigned one. `beq` and `bne` are unaffected — equality does not care.

**9. Are immediates sign-extended even for the unsigned comparisons?**

Yes. In RISC-V every immediate is sign-extended. `bltu` and `bgeu` do an
unsigned *comparison* of sign-extended values.

**10. What is `li` in the disassembly?**

A pseudo-instruction. Small values assemble to one `addi`; large ones to
`lui` + `addi`. That is why almost every compiled test needs `lui`.

**11. `lui` says `R[rd] = imm << 12`, but the U-immediate is already shifted. Do I
shift again?**

No. If `sxt_imm_DE` already built the U-immediate with the low 12 bits zeroed,
`lui` just passes it through.

**12. In the ISA description `srai`, `srli` and `slli` have no immediate type. What
do I use?**

The I-immediate, but only its low 5 bits (`inst[24:20]`) are the shift amount.
`sra`, `srl` and `sll` likewise use only the low 5 bits of `rs2`.

**13. What do `slti` / `sltiu` produce?**

0 or 1. They set `rd` to 1 when `R[rs1] < sext(imm)` — signed for `slti`,
unsigned for `sltiu`.

**14. I get `%Warning-LATCH: Latch inferred for signal ...`.**

A combinational `always @(*)` block that does not assign its output on every
path. Add the missing `default` arm or `else` branch. Do not silence it with
`/* verilator lint_off LATCH */` unless you are certain the latch is intended —
in this lab it never is.

**15. Can I add new files?**

Yes, as long as `make submit` picks them up (it zips `*.v`, `*.vh`,
`sim_main.cpp` and the `Makefile`).
