#include "tester.h"

int main()
{
    struct Equation tests[N_TESTS];
    read_tests("tests.txt", tests, N_TESTS);
    printf("Number of passed tests: %d / %d\n", test_solver(tests, N_TESTS), N_TESTS);
    printf("Number of passed random tests: %d / %d\n", test_rand(N_RAND_TESTS), N_RAND_TESTS);
    return 0;
}