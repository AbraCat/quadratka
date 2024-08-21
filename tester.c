
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
        passed = iszero(e.n_roots - tests->n_roots) && iszero(e.x1 - tests->x1) && iszero(e.x2 - tests->x2) ? 1 : 0;
        right_cnt += passed;
        if (!passed)
            printf("test %d failed\na = %lf, b = %lf, c = %lf\n"
            "Your answer: n_roots = %d, x1 = %lf, x2 = %lf\n"
            "Correct answer: n_roots = %d, x1 = %lf, x2 = %lf\n", 
            N_TESTS - e_num, tests->a, tests->b, tests->c, e.n_roots, e.x1, e.x2, tests->n_roots, tests->x1, tests->x2);
        ++tests;
    }
    return right_cnt;
}
void read_tests(char* file_name, struct Equation* tests, int n_tests)
{
    FILE* file = fopen(file_name, "r");
    int i = 0;
    for (i = 0; i != n_tests; ++i)
    {
        fscanf(file, "%lf %lf %lf %d %lf %lf\n", &tests[i].a, &tests[i].b, &tests[i].c, &tests[i].n_roots, &tests[i].x1, &tests[i].x2);
    }
    fclose(file);
}