        addi  t0, x0, -8
        addi  t1, x0, 3
        xori  t2, t1, 5
        addi  t3, x0, 6
        beq   t2, t3, c1
        addi  gp, x0, 2
        .halt
c1:
        slli  t2, t1, 4
        addi  t3, x0, 48
        beq   t2, t3, c2
        addi  gp, x0, 3
        .halt
c2:
        srli  t2, t0, 28
        addi  t3, x0, 15
        beq   t2, t3, c3
        addi  gp, x0, 4
        .halt
c3:
        srai  t2, t0, 1
        addi  t3, x0, -4
        beq   t2, t3, c4
        addi  gp, x0, 5
        .halt
c4:
        sltu  t2, t1, t0
        addi  t3, x0, 1
        beq   t2, t3, ok
        addi  gp, x0, 6
        .halt
ok:
        addi  gp, x0, 1
        .halt
