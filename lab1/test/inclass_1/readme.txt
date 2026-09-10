Three tests for In-Class Session 1, using only add and addi. No branches.
Each one sets gp (x3) to 1 when it is correct, so the simulator prints "Passed!"; otherwise it prints "Failed. exitcode: N", where N is the value gp ended up with.

Run one:        IDMEMINITFILE=$PWD/test/inclass_1/test2.mem make tests
Run all three:  ./run_tests.sh inclass_1

  test1   add immediate
  test2   add with dependency
  test3   add with negative immediate
