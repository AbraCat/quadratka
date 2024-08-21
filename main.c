#include "tester.h"

int main()
{
    struct Equation el[N_TESTS] = {
        {0, 0, 0, INF_ROOTS, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0},
        {0, 1, 1, 1, -1, 0},
        {1, 1, 1, 0, 0, 0},
        {1, 2, 1, 1, -1, 0},
        {1, 2, -3, 2, -3, 1}
    };

    printf("Number of passed tests: %d / %d\n", test_solver(el, N_TESTS), N_TESTS);
    return 0;
}