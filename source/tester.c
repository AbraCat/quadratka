
#include <tester.h>
int testSolver(struct Equation* tests, int n_tests)
{
    struct Equation e;
    initEquation(&e);
    int right_cnt = 0, passed = 0;
    for (int i = 0; i != n_tests; ++i)
    {
        setCoeff(&e, tests->a, tests->b, tests->c);
        solveQuadratic(&e);
        passed = iszero(e.n_roots - tests->n_roots) && iszero(e.x1 - tests->x1) && iszero(e.x2 - tests->x2) ? 1 : 0;
        right_cnt += passed;
        if (!passed) {
            printf(RED "test %d failed" DEFAULT "\na = %lf, b = %lf, c = %lf\n"
            "Your answer: n_roots = %d, x1 = %lf, x2 = %lf\n"
            "Correct answer: n_roots = %d, x1 = %lf, x2 = %lf\n", 
            i + 1, tests->a, tests->b, tests->c, e.n_roots, e.x1, e.x2, tests->n_roots, tests->x1, tests->x2);
        }
        ++tests;
    }
    return right_cnt;
}
int testRand(int n_tests)
{
    srand((unsigned)time(NULL));
    struct Equation e;
    initEquation(&e);
    int n_correct = 0, correct = 0;
    double res1 = 0, res2 = 0;
    for (int i = 0; i != n_tests; ++i)
    {
        setCoeff(&e, genRand(1000), genRand(1000), genRand(1000));
        solveQuadratic(&e);
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
            printf(RED "random test %d failed" DEFAULT "\na = %lf, b = %lf, c = %lf\n"
            "Your answer: n_roots = %d, x1 = %lf, x2 = %lf\n"
            "Left side evaluates to: %lf, %lf\n", 
            i + 1, e.a, e.b, e.c, e.n_roots, e.x1, e.x2, res1, res2);
        }
        n_correct += correct;
    }
    return n_correct;
}
double genRand(int rand_max)
{
    return (1.0 * rand() - RAND_MAX / 2) / (RAND_MAX / 2) * rand_max;
}
struct Equation* readTests(const char* file_name, int *n_tests, int *error)
{
    assert(file_name != NULL && n_tests != NULL && error != NULL);

    FILE* file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf(RED "readTests(): couldn't open file" DEFAULT "\n");
        fclose(file);
        *error = 1;
        return NULL;
    }
    if (!fscanf(file, "%d", n_tests))
    {
        fclose(file);
        *error = 2;
        return NULL;
    }
    struct Equation* tests = calloc(*n_tests, sizeof(struct Equation));
    for (int i = 0; i != *n_tests; ++i)
    {
        if (fscanf(file, "%lf %lf %lf %d %lf %lf\n", &tests[i].a, &tests[i].b, &tests[i].c, &tests[i].n_roots, &tests[i].x1, &tests[i].x2) != 6)
        {
            fclose(file);
            *error = 2;
            return NULL;
        }
    }
    fclose(file);
    *error = 0;
    return tests;
}
int readAndTest(const char* file, int* n_tests)
{
    assert(n_tests !=  NULL);

    FILE *fp = fopen(file, "r");
    if (fp == NULL)
        return -2;
    if (fscanf(fp, "%d", n_tests) == 0)
    {
        *n_tests = 0;
        fclose(fp);
        return -1;
    }
    struct Equation test, e;
    initEquation(&e);
    initEquation(&test);
    int ch = '\0', correct_cnt = 0, passed = 0;
    for (int i = 0; i != *n_tests; ++i)
    {
        if (fscanf(fp, "%lf %lf %lf %d %lf %lf", &test.a, &test.b, &test.c, &test.n_roots, &test.x1, &test.x2) != 6)
        {
            fclose(fp);
            return -1;
        }
        while ((ch = getc(fp)) != '\n' && ch != EOF)
        {
            if (!isspace(ch))
            {
                fclose(fp);
                return -1;
            }
        }
        setCoeff(&e, test.a, test.b, test.c);
        solveQuadratic(&e);
        passed = iszero(e.n_roots - test.n_roots) && iszero(e.x1 - test.x1) && iszero(e.x2 - test.x2) ? 1 : 0;
        if (!passed) {
            printf(RED "test %d failed" DEFAULT "\na = %lf, b = %lf, c = %lf\n"
            "Your answer: n_roots = %d, x1 = %lf, x2 = %lf\n"
            "Correct answer: n_roots = %d, x1 = %lf, x2 = %lf\n", 
            i + 1, test.a, test.b, test.c, e.n_roots, e.x1, e.x2, test.n_roots, test.x1, test.x2);
        }
        correct_cnt += passed;
    }
    return correct_cnt;
}