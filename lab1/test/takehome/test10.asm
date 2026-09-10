        addi  gp, x0, 0
        addi  t0, x0, 0x210
        jalr  ra, t0, 8
        addi  gp, gp, 4
        addi  gp, gp, 2
        .halt
target:
        addi  t1, x0, 0x20c
        bne   ra, t1, bad
        addi  gp, gp, 1
        .halt
bad:
        addi  gp, gp, 7
        .halt
