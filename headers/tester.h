#ifndef TESTER_H
#define TESTER_H

#include <stdlib.h>
#include <time.h>
#include <solver.h>
#include <colors.h>
#include <string.h>

/**
 * ... text ...
 */
int testSolver(struct Equation* tests, int n_tests);

int testRand(int n_tests);
int readTests(char* file_name, struct Equation* tests, int n_tests);
double genRand(void);

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
int readAndTest(char* file, int *n_tests);

#endif // TESTER_H