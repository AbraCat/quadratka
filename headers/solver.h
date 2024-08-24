#ifndef SOLVER_H
#define SOLVER_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stddef.h>
#include <ctype.h>

#include <custom.h>

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

/*! \brief Scans coefficients (a, b, c) from stdin. Give a user MAX_ATTEMPST attempts.
* \param e Equation that will store scanned coefficients.
* \return 0 if scanned successfully, nonzero otherwise.
 */
int scanCoeff(struct Equation* e);

/*! \brief Initializes all members of e with zeros.
\param e Equation that will be initialized
 */
void initEquation(struct Equation* e);

/*! \brief Sets coefficients (a, b, c) of struct Equation.
\param e Equation that will store coeffictients
\param a a coeff
\param b b coeff
\param c c coeff
 */
void setCoeff(struct Equation* e, double a, double b, double c);

/*! \brief Solves linear equation (a * x + b = 0).
\param a a coeff
\param b b coeff
\param x will store a root if it exists
\return number of roots
 */
int solveLinear(double a, double b, double *x);

/*! \brief Solves quadratic equation defined by coefficients of e.
\param e Equation that should have coefficients and will store roots
 */
void solveQuadratic(struct Equation* e);

/*! \brief Prints a number of roots and each root stored in e.
\param e Equation that stores roots
 */
void printRoots(struct Equation* e);

void helpFunc();

#endif // SOLVER_H