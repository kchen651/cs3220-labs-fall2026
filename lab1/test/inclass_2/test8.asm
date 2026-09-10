        addi  t1, x0, -1
        addi  t2, x0, 1
        addi  gp, x0, 0
        bgeu  t1, t2, taken
        addi  gp, gp, 4
        .halt
taken:
        addi  gp, gp, 1
        bltu  t1, t2, wrong
        .halt
wrong:
        addi  gp, gp, 8
        .halt
