        addi  t1, x0, 1
        addi  t2, x0, 1
        addi  gp, x0, 0
        beq   t1, t2, success
        addi  gp, gp, 4
        addi  gp, gp, 4
        addi  gp, gp, 2
success:
        addi  gp, gp, 1
        .halt
