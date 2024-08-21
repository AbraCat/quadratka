#include <stdlib.h>
#include <time.h>
#include "solver.h"
int test_solver(struct Equation* tests, int n_tests);
int test_rand(int n_tests);
void read_tests(char* file_name, struct Equation* tests, int n_tests);
double gen_rand(void);