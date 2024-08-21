#include "tester.h"

int main()
{
    struct Equation tests[N_TESTS];
    read_tests("tests.txt", tests, N_TESTS);
    printf("Number of passed tests: %d / %d\n", test_solver(tests, N_TESTS), N_TESTS);
    return 0;
}