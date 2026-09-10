Five tests for In-Class Session 2, covering the six conditional branches. They also use add and addi, so In-Class 1 has to be working first.
Each one sets gp (x3) to 1 when it is correct, so the simulator prints "Passed!"; otherwise it prints "Failed. exitcode: N", where N is the value gp ended up with.

Run one:       IDMEMINITFILE=$PWD/test/inclass_2/test4.mem make tests
Run all five:  ./run_tests.sh inclass_2

  test4   beq instruction
  test5   beq instruction
  test6   bne instruction
  test7   blt / bge instruction
  test8   bltu / bgeu instruction

