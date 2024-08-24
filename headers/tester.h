#ifndef TESTER_H
#define TESTER_H

#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <solver.h>
#include <colors.h>

/*! \brief Runs n_tests from array tests. Returns number of passed tests.
\param tests array of tests
\param n_tests number of tests
\return number of passed tests
 */
int testSolver(struct Equation* tests, int n_tests);

/*! \brief Runs n_tests random tests. Returns number of passed tests.
\param n_tests number of tests
\return number of passed tests
 */
int testRand(int n_tests);

long fileSize(FILE *file);

int nLines(const char* s);

struct Equation* getTests(const char* s, int n_lines, int* error);

char* readFile(FILE* file, int *n_chars, int *error);

/*! \brief (old docs) Reads tests from specified file in an array.

File should contain n_tests lines. Each line should contain 6 mumbers and represent a single test.
* \param file_name path to file containing tests
* \param tests array that will store tests
* \param n_tests number of tests
* \return 0 if errors occur nored, nonzero otherwise
 */
struct Equation* readTests(const char* file_name, int *n_tests, int *error);

/*! \brief Generates a random double from -rand_max to rand_max
\param rand_max boundary for a generated number
 */
double genRand(int rand_max);

/*! \brief Reads tests from a file and runs them.
\param file path to file
\param n_tests int that will store number of tests
\return number of passed tests
 */
int readAndTest(const char* file, int *n_tests);

#endif // TESTER_H