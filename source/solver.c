#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stddef.h>
#include <ctype.h>

#include <solver.h>
#include <custom.h>

int scanCoeff(struct Equation* e)
{
    assert(e != NULL);

    int ch = '\0';
    for (int i = 0; i != MAX_ATTEMPTS; ++i)
    {
        int success = scanf("%lf %lf %lf", &e->a, &e->b, &e->c) == 3;
        while ((ch = getchar()) != '\n')
        {
            if (ch == EOF) return EOF;
            if (!isspace(ch)) success = 0;
        }
        if (success) return 0;
        if (i != MAX_ATTEMPTS - 1)
            printf("Wrong input format. Try again: ");
    }
    return 1;
}
void initEquation(struct Equation* e)
{
    assert(e != NULL);

    e->n_roots = 0;
    e->a = e->b = e->c = e->x1 = e->x2 = 0;
}
void setCoeff(struct Equation* e, double a, double b, double c)
{
    assert(e != NULL);

    e->a= a;
    e->b = b;
    e->c = c;
}
int solveLinear(double a, double b, double *x)
{
    // ax + b = 0

    assert(isfinite(a));
    assert(isfinite(b));
    assert(x != NULL);

    if (iszero(a))
    {
        *x = 0;
        if (iszero(b))
            return INF_ROOTS;
        return 0;
    }
    *x = -b / a;
    return 1;
}
void solveQuadratic(struct Equation* e)
{
    // ax**2 + bx + c = 0

    assert(e != NULL);

    if (iszero(e->a))
    {
        e->n_roots = solveLinear(e->b, e->c, &(e->x1));
        e->x2 = 0;
        return;
    }
    double d = e->b * e->b - 4 * e->a * e->c;
    if (iszero(d))
    {
        e->x1 = -e->b / (e->a * 2);
        e->x2 = 0;
        e->n_roots = 1;
        return;
    }
    if (d < 0) 
    {
        e->x1 = e->x2 = 0;
        e->n_roots = 0;
        return;
    }
    e->x1 = (-e->b - sqrt(d)) / (e->a * 2);
    e->x2 = (-e->b + sqrt(d)) / (e->a * 2);
    if (e->x1 > e->x2)
    {
        double temp = e->x1;
        e->x1 = e->x2;
        e->x2 = temp;
    }
    e->n_roots = 2;
}
void printRoots(struct Equation* e)
{
    assert(e != NULL);

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
            printf("printRoots(): wrong number of roots\n");
            break;
    }
}
void helpFunc()
{
    printf("Help message\n");
}