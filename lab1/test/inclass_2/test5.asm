        addi  t1, x0, 1
        addi  t2, x0, 2
        addi  gp, x0, 0
        beq   t1, t2, wrong
        addi  gp, gp, 1
        .halt
wrong:
        addi  gp, gp, 5
        .halt
