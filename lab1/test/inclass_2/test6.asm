        addi  t1, x0, 1
        addi  t2, x0, 2
        addi  gp, x0, 0
        bne   t1, t2, taken
        addi  gp, gp, 4
        .halt
taken:
        addi  gp, gp, 1
        bne   t1, t1, wrong
        .halt
wrong:
        addi  gp, gp, 8
        .halt
