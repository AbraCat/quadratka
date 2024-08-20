#include <stdio.h>
#include <math.h>
#include <assert.h>
#define INF_ROOTS -1
//const int INF_ROOTS = -1;
const double EPS = 1e-6;
const int MAX_ATTEMPTS = 3;
int iszero(double x) 
{
    return fabs(x) < EPS;
}
int scan(double *a, double *b, double *c)
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
int solve_quadratic(double a, double b, double c, double *x1, double *x2)
{
    // ax**2 + bx + c = 0

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    if (iszero(a))
        return solve_linear(b, c, x1);
    double d = b * b - 4 * a * c;
    if (iszero(d))
    {
        *x1 = -b / (a * 2);
        return 1;
    }
    if (d < 0) return 0;
    *x1 = (-b - sqrt(d)) / (a * 2);
    *x2 = (-b + sqrt(d)) / (a * 2);
    return 2;
}
void print_roots(int n_root, double x1, double x2)
{
    switch (n_root)
    {
        case 0:
            printf("No solution\n");
            break;
        case 1:
            printf("1 root: %lf\n", x1);
            break;
        case 2:
            printf("2 roots: %lf, %lf\n", x1, x2);
            break;
        case INF_ROOTS:
            printf("Any real number\n");
            break;
        default:
            printf("print(): wrong number of roots\n");
            break;
    }
}
int main()
{
    printf("Program for solving quadratic equations in form a*x^2 + b*x + c\nEnter coeffiients (a, b, c): ");
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    if (scan(&a, &b, &c))
    {
        printf("Number of input attempts exceeded\n");
        return 1;
    }
    int n_root = solve_quadratic(a, b, c, &x1, &x2);
    print_roots(n_root, x1, x2);
    return 0;
}