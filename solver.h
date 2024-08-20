#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stddef.h>

enum ERootsCount;
const int MAX_ATTEMPTS;

struct Equation
{
    int n_roots;
    double a, b, c, x1, x2;
};

int iszero(double x);
int scan_coeff(double *a, double *b, double *c);
void init_equation(struct Equation* e);
void set_coeff(struct Equation* e, double a, double b, double c);
int solve_linear(double a, double b, double *x);
void solve_quadratic(struct Equation* e);
void print_roots(struct Equation* e);