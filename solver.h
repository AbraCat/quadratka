#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stddef.h>

enum ERootsCount;
const int MAX_ATTEMPTS;

int iszero(double x);
int scan(double *a, double *b, double *c);
int solve_linear(double a, double b, double *x);
int solve_quadratic(double a, double b, double c, double *x1, double *x2);
void print_roots(int n_root, double x1, double x2);