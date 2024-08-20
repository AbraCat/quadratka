#include "solver.h"

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