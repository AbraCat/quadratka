
#include "tester.h"
int test_solver(struct Equation* tests, int n_tests)
{
    struct Equation e;
    init_equation(&e);
    int right_cnt = 0, passed = 0;
    for (int i = 0; i != n_tests; ++i)
    {
        set_coeff(&e, tests->a, tests->b, tests->c);
        solve_quadratic(&e);
        passed = iszero(e.n_roots - tests->n_roots) && iszero(e.x1 - tests->x1) && iszero(e.x2 - tests->x2) ? 1 : 0;
        right_cnt += passed;
        if (!passed)
            printf("test %d failed\na = %lf, b = %lf, c = %lf\n"
            "Your answer: n_roots = %d, x1 = %lf, x2 = %lf\n"
            "Correct answer: n_roots = %d, x1 = %lf, x2 = %lf\n", 
            i + 1, tests->a, tests->b, tests->c, e.n_roots, e.x1, e.x2, tests->n_roots, tests->x1, tests->x2);
        ++tests;
    }
    return right_cnt;
}
int test_rand(int n_tests)
{
    struct Equation e;
    init_equation(&e);
    int n_correct = 0, correct = 0;
    double res1 = 0, res2 = 0;
    for (int i = 0; i != n_tests; ++i)
    {
        set_coeff(&e, gen_rand(), gen_rand(), gen_rand());
        solve_quadratic(&e);
        res1 = res2 = 0;
        switch (e.n_roots)
        {
            case 2:
                res1 = e.a * e.x1 * e.x1 + e.b * e.x1 + e.c;
                res2 = e.a * e.x2 * e.x2 + e.b * e.x2 + e.c;
                break;
            case 1:
                res1 = e.a * e.x1 * e.x1 + e.b * e.x1 + e.c;
                break;
            case 0:
                break;
            default:
                break;
        }
        correct = (iszero(res1) && iszero(res2)) ? 1 : 0;
        if (!correct)
        {
            printf("test %d failed\na = %lf, b = %lf, c = %lf\n"
            "Your answer: n_roots = %d, x1 = %lf, x2 = %lf\n"
            "Left side evaluates to: %lf, %lf\n", 
            i + 1, e.a, e.b, e.c, e.n_roots, e.x1, e.x2, res1, res2);
        }
        n_correct += correct;
    }
    return n_correct;
}
double gen_rand(void)
{
    return (1.0 * rand() - RAND_MAX / 2) / (RAND_MAX / 2) * 10;
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