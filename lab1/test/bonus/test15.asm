        addi  t0, x0, 0x400
        addi  t1, x0, 42
        sw    t1, 0(t0)
        lw    t2, 0(t0)
        addi  t3, x0, 42
        beq   t2, t3, c1
        addi  gp, x0, 2
        .halt
c1:
        addi  t1, x0, -7
        sw    t1, 8(t0)
        lw    t2, 8(t0)
        addi  t3, x0, -7
        beq   t2, t3, c2
        addi  gp, x0, 3
        .halt
c2:
        lw    t2, 0(t0)
        addi  t3, x0, 42
        beq   t2, t3, ok
        addi  gp, x0, 4
        .halt
ok:
        addi  gp, x0, 1
        .halt
