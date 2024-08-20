#include <stdio.h>
#include <math.h>
#define solve_inf_roots -1
//const int solve_inf_roots = -1;
int scan(double *a, double *b, double *c)
{
    int n_coeff = scanf("%lf %lf %lf", a, b, c);
    if (n_coeff != 3) return 1;
    return 0;
}
int solve(double a, double b, double c, double *x1, double *x2)
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0) return solve_inf_roots;
            return 0;
        }
        *x1 = -c / b;
        return 1;
    }
    double d = b * b - 4 * a * c;
    if (d < 0) return 0;
    if (d == 0)
    {
        *x1 = -b / (a * 2);
        return 1;
    }
    *x1 = (-b - sqrt(d)) / (a * 2);
    *x2 = (-b + sqrt(d)) / (a * 2);
    return 2;
}
int main()
{
    printf("# Program for solving quadratic equations in form a*x^2 + b*x + c\n\nEnter coeffiients (a, b, c): ");
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    if (scan(&a, &b, &c))
    {
        printf("Wrong input. Goodbye.");
        return 1;
    }
    int n_root = solve(a, b, c, &x1, &x2);
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
        case solve_inf_roots:
            printf("Any real number\n");
            break;
    }
    return 0;
}