#include <solver.h>
#include <tester.h>
#include <string.h>

int mainSolve(int argc, char* argv[]);
int mainTest(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    if (argc > 1 && !strcmp(argv[1], "-t"))
        return mainTest(argc, argv);
    return mainSolve(argc, argv);
}

int mainSolve(int argc, char* argv[])
{
    // aaaaaaaaa
    
    printf("Program for solving quadratic equations in form a*x^2 + b*x + c\nEnter coeffiients (a, b, c): ");
    struct Equation e;
    initEquation(&e);
    switch (scanCoeff(&e))
    {
        case 1:
            printf("Number of input attempts exceeded\n");
            return 1;
        case EOF:
            printf("Reached end of file\n");
            return -1;
    }
    solveQuadratic(&e);
    printRoots(&e);
    return 0;
}
int mainTest(int argc, char* argv[])
{
    struct Equation tests[N_TESTS];
    readTests("./txt/tests.txt", tests, N_TESTS);
    printf("Number of passed tests: %d / %d\n", testSolver(tests, N_TESTS), N_TESTS);
    printf("Number of passed random tests: %d / %d\n", testRand(N_RAND_TESTS), N_RAND_TESTS);
    return 0;
}