
#include "tester.h"
int test_solver(struct Equation* tests, int e_num)
{
    struct Equation e;
    init_equation(&e);
    int right_cnt = 0, passed = 0;
    while (e_num--)
    {
        set_coeff(&e, tests->a, tests->b, tests->c);
        solve_quadratic(&e);
        passed = e.n_roots == tests->n_roots && e.x1 == tests->x1 && e.x2 == tests->x2 ? 1 : 0;
        right_cnt += passed;
        if (!passed)
            printf("test %d failed\n", N_TESTS - e_num);
        ++tests;
    }
    return right_cnt;
}