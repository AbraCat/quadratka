#include "solver.h"

int main()
{
    printf("Program for solving quadratic equations in form a*x^2 + b*x + c\nEnter coeffiients (a, b, c): ");
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    if (scan_coeff(&a, &b, &c))
    {
        printf("Number of input attempts exceeded\n");
        return 1;
    }
    struct Equation e;
    init_equation(&e);
    set_coeff(&e, a, b, c);
    solve_quadratic(&e);
    print_roots(&e);
    return 0;
}