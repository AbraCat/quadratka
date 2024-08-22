#ifndef TESTER_H
#define TESTER_H

#include <stdlib.h>
#include <time.h>
#include <solver.h>
#include <colors.h>
int testSolver(struct Equation* tests, int n_tests);
int testRand(int n_tests);
int readTests(char* file_name, struct Equation* tests, int n_tests);
double genRand(void);
int readAndTest(char* file, int *n_tests);

#endif // TESTER_H