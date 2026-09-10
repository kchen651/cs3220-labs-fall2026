        addi  gp, x0, 0
        jal   ra, target
        addi  gp, gp, 4
        addi  gp, gp, 4
        addi  gp, gp, 2
        .halt
target:
        addi  t0, x0, 0x208
        bne   ra, t0, bad
        addi  gp, gp, 1
        .halt
bad:
        addi  gp, gp, 7
        .halt
