#!/bin/bash
#
# Run every .mem program in one test suite and report pass/fail counts.
#
#   ./run_tests.sh inclass_1   the three hand-written In-Class 1 tests
#   ./run_tests.sh inclass_2   the five hand-written In-Class 2 tests
#   ./run_tests.sh takehome    the compiled RISC-V test programs
#   ./run_tests.sh bonus       the optional ones
#   ./run_tests.sh all         all four, one summary each
#
# Each run leaves two files behind:
#   <suite>_tests.log    the full console output of every test
#   <suite>_results.log  one TESTING/Passed/Failed line per test
#
# IDMEMINITFILE is passed through to verilator as a +define+, so your own
# define.vh is never modified by this script.
#
# A full "takehome" run rebuilds the simulator once per test, so expect it to
# take several minutes.  While you are working on one instruction, run that one
# test on its own instead:
#   IDMEMINITFILE=$PWD/test/takehome/lw.mem make tests

suite=$1

run_suite() {
    local s=$1
    local dir="$PWD/test/$s"

    if [ ! -d "$dir" ]; then
        echo "No such test directory: $dir"
        return 1
    fi

    rm -f "${s}_tests.log" "${s}_results.log"

    echo "RUNNING ${s}"
    echo
    for filename in "$dir"/*.mem; do
        echo >> "${s}_tests.log"
        echo "TESTING: $filename" >> "${s}_tests.log"
        IDMEMINITFILE=$filename make tests >> "${s}_tests.log" 2>&1
    done

    grep -E 'TESTING|Failed|Passed' "${s}_tests.log" > "${s}_results.log"

    # Count from the one-line-per-test summary, not from the raw log: the raw
    # log also contains the word "failed" inside compiler and verilator output.
    echo "Total number of tests:"
    grep -c '^TESTING:' "${s}_results.log"
    echo "Number of passed tests:"
    grep -c '^Passed!' "${s}_results.log"
    echo "Number of failed tests:"
    grep -c '^Failed\.' "${s}_results.log"

    # List the ones that failed, so you know where to look.
    if grep -q '^Failed\.' "${s}_results.log"; then
        echo "Failing tests:"
        awk '/^TESTING:/ { name = $2 } /^Failed\./ { print "  " name "  (" $0 ")" }' \
            "${s}_results.log"
    fi
    echo
}

case $suite in
    inclass_1|inclass_2|takehome|bonus)
        echo "You have chosen to run the $suite tests"
        run_suite "$suite"
        ;;
    all)
        echo "You have chosen to run all tests"
        for s in inclass_1 inclass_2 takehome bonus; do
            run_suite "$s"
        done
        ;;
    *)
        echo "Usage: ./run_tests.sh {inclass_1|inclass_2|takehome|bonus|all}"
        exit 1
        ;;
esac
