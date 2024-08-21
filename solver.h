#ifndef SOLVER_H
#define SOLVER_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stddef.h>

static const int N_TESTS = 8;
static const int N_RAND_TESTS = 5;
static const int MAX_ATTEMPTS = 3;

enum ERootsCounts {
    INF_ROOTS = -1
};

struct Equation
{
    double a, b, c;
    int n_roots;
    double x1, x2;
};

int iszero(double x);
int scanCoeff(double *a, double *b, double *c);
void initEquation(struct Equation* e);
void setCoeff(struct Equation* e, double a, double b, double c);
int solveLinear(double a, double b, double *x);
void solveQuadratic(struct Equation* e);
void printRoots(struct Equation* e);

#endif // SOLVER_H