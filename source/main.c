#include <solver.h>
#include <tester.h>
#include <string.h>
#include <assertCustom.h>

int mainSolve(int argc, char* argv[]);
int mainTest(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    assertCustom(1);
    if (argc > 1 && !strcmp(argv[1], "-t"))
        return mainTest(argc, argv);
    return mainSolve(argc, argv);
}

int mainSolve(int argc, char* argv[])
{
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
    int n_tests = 0;
    int correct_cnt = readAndTest(".\\txt\\tests.txt", &n_tests);
    if (correct_cnt < 0)
    {
        switch (correct_cnt)
        {
            case -1:
                printf(RED "Wrong file format\n" DEFAULT);
                break;
        }
        return 1;
    }
    printf("Number of passed tests: %d / %d\n", correct_cnt, n_tests);
    printf("Number of passed random tests: %d / %d\n", testRand(N_RAND_TESTS), N_RAND_TESTS);
    return 0;
}