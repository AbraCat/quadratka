#include <stdio.h>
#include <math.h>
#include <assert.h>
#define INF_ROOTS -1
//const int INF_ROOTS = -1;
const double EPS = 1e-6;
int scan(double *a, double *b, double *c)
{
    assert(a != b);
    assert(a != c);
    assert(b != c);

    int n_coeff = scanf("%lf %lf %lf", a, b, c);
    if (n_coeff != 3) return 1;
    return 0;
}
int solve(double a, double b, double c, double *x1, double *x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    if (fabs(a) < EPS)
    {
        if (fabs(b) < EPS)
        {
            if (fabs(c) < EPS) return INF_ROOTS;
            return 0;
        }
        *x1 = -c / b;
        return 1;
    }
    double d = b * b - 4 * a * c;
    if (d < 0) return 0;
    if (fabs(d) < EPS)
    {
        *x1 = -b / (a * 2);
        return 1;
    }
    *x1 = (-b - sqrt(d)) / (a * 2);
    *x2 = (-b + sqrt(d)) / (a * 2);
    return 2;
}
void print(int n_root, double x1, double x2)
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
    }
}
int main()
{
    printf("# Program for solving quadratic equations in form a*x^2 + b*x + c\n\nEnter coeffiients (a, b, c): ");
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    if (scan(&a, &b, &c))
    {
        printf("\nWrong input.\n");
        return 1;
    }
    putchar('\n');
    int n_root = solve(a, b, c, &x1, &x2);
    print(n_root, x1, x2);
    return 0;
}