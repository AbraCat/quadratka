#include <getopt.h>
#include <string.h>

#include <solver.h>
#include <tester.h>
#include <custom.h>

int mainSolve(int argc, char* argv[]);
int mainTest(int argc, char* argv[]);
int mainTest2(int agrc, char* argv[]);

int main(int argc, char* argv[])
{
    //assertCustom(1);

    //return printfCustom("%d %f %s %R %c %% %ld %lf %D %hd %lld %hhd %f %f %f\n", 1, 1.1, "aaa", 'b', (long int)2, 2.2, (short int)3, (long long)4, 
    //(signed char)5, -0.9, 0.00001, 0.000009);

    // const char* file_name = ".\\txt\\test-file.txt";
    // FILE *file = fopen(file_name, "r");
    // int n_chars = 0, error = 0;
    // char* s = readFile(file, &n_chars, &error);
    // if (s == NULL)
    // {
    //     switch(error)
    //     {
    //         case 1:
    //             printf(RED "Error\n" DEFAULT);
    //             break;
    //         default:
    //             printf("Unknown error\n");
    //             break;
    //     }
    //     fclose(file);
    //     return 1;
    // }
    // int n_lines = nLines(s);
    // printf("%d %s\n", n_chars, s);
    // printf("%d\n", n_lines);
    // fclose(file);
    // free(s);
    // return 0;

    int help = 0, t = 0, T = 0;
    struct option longopts[2] = {{"help", 0, NULL, 1}, {NULL, 0, NULL, 0}};
    int val = 0, longindex_int = 0;
    int *longindex = &longindex_int;
    for (int i = 1; i != argc; ++i)
    {
        val = getopt_long(argc, argv, "tT", longopts, longindex);
        if (val == 1)
            help = 1;
        else if (val == 't')
            t = 1;
        else if (val == 'T')
            T = 1;
    }
    if (help)
    {
        helpFunc();
        return 0;
    }
    if (t)
        return mainTest(argc, argv);
    if (T)
        return mainTest2(argc, argv);
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
        case 0:
            break;
        default:
            printf("Unknown error\n");
    }
    solveQuadratic(&e);
    printRoots(&e);
    return 0;
}
int mainTest(int argc, char* argv[])
{
    // -t

    int n_tests = 0;
    int correct_cnt = readAndTest(".\\txt\\tests.txt", &n_tests);
    if (correct_cnt < 0)
    {
        switch (correct_cnt)
        {
            case -1:
                printf(RED "Wrong file format\n" DEFAULT);
                break;
            case -2:
                printf(RED "Error: %s\n" DEFAULT, strerror(errno));
                break;
            default:
                printf("Unknown error\n");
                break;
        }
        return 1;
    }
    printf("Number of passed tests: %d / %d\n", correct_cnt, n_tests);
    printf("Number of passed random tests: %d / %d\n", testRand(N_RAND_TESTS), N_RAND_TESTS);
    return 0;
}
int mainTest2(int agrc, char* argv[])
{
    // -T

    const char* file_name = ".\\txt\\tests2.txt";
    FILE *file = fopen(file_name, "r");
    int n_chars = 0, error = 0;
    char* s = readFile(file, &n_chars, &error);
    if (s == NULL)
    {
        switch(error)
        {
            case 1:
                printf(RED "Error\n" DEFAULT);
                break;
            default:
                printf("Unknown error\n");
                break;
        }
        fclose(file);
        return 1;
    }
    int n_lines = nLines(s);
    struct Equation* tests = getTests(s, n_lines, &error);
    if (tests == NULL) 
    {
        switch (error)
        {
            case 1:
                printf(RED "Error: %s\n" DEFAULT, strerror(errno));
                break;
            case 2:
                printf(RED "Wrong file format\n" DEFAULT);
                break;
            case 3:
                printf(RED "Counln't allocate memory for tests\n" DEFAULT);
                break;
            default:
                printf("Unknown error\n");
                break;
        }
        return 1;
    }
    int correct_cnt = testSolver(tests, n_lines);
    printf("Number of passed tests: %d / %d\n", correct_cnt, n_lines);
    printf("Number of passed random tests: %d / %d\n", testRand(N_RAND_TESTS), N_RAND_TESTS);
    free(tests);
    return 0;
}