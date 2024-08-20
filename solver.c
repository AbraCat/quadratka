#include "solver.h"

const int MAX_ATTEMPTS = 3;
enum ERootsCounts {
    INF_ROOTS = -1
};

int iszero(double x) 
{
    const double EPS = 1e-6;
    return fabs(x) < EPS;
}
int scan_coeff(double *a, double *b, double *c)
{
    assert(a != b);
    assert(a != c);
    assert(b != c);

    int n_attempts = 0;
    while (scanf("%lf %lf %lf", a, b, c) != 3)
    {
        if (++n_attempts == MAX_ATTEMPTS) return 1;
        while (getchar() != '\n');
        printf("Wrong input format. Try again: ");
    }
    return 0;
}
void init_equation(struct Equation* e)
{
    assert(e != NULL);
    e->n_roots = e->a = e->b = e->c = e->x1 = e->x2 = 0;
}
void set_coeff(struct Equation* e, double a, double b, double c)
{
    assert(e != NULL);
    e->a= a;
    e->b = b;
    e->c = c;
}
int solve_linear(double a, double b, double *x)
{
    // ax + b = 0
    
    assert(isfinite(a));
    assert(isfinite(b));
    assert(x != NULL);
    if (iszero(a))
    {
        if (iszero(b))
            return INF_ROOTS;
        return 0;
    }
    *x = -b / a;
    return 1;
}
void solve_quadratic(struct Equation* e)
{
    // ax**2 + bx + c = 0

    assert(e != NULL);

    if (iszero(e->a))
    {
        e->n_roots = solve_linear(e->b, e->c, &(e->x1));
        return;
    }
    double d = e->b * e->b - 4 * e->a * e->c;
    if (iszero(d))
    {
        e->x1 = -e->b / (e->a * 2);
        e->n_roots = 1;
        return;
    }
    if (d < 0) 
    {
        e->n_roots = 0;
        return;
    }
    e->x1 = (-e->b - sqrt(d)) / (e->a * 2);
    e->x2 = (-e->b + sqrt(d)) / (e->a * 2);
    e->n_roots = 2;
}
void print_roots(struct Equation* e)
{
    switch (e->n_roots)
    {
        case 0:
            printf("No solution\n");
            break;
        case 1:
            printf("1 root: %lf\n", e->x1);
            break;
        case 2:
            printf("2 roots: %lf, %lf\n", e->x1, e->x2);
            break;
        case INF_ROOTS:
            printf("Any real number\n");
            break;
        default:
            printf("print(): wrong number of roots\n");
            break;
    }
}