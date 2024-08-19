#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                printf("Any real number\n");
                return 0;
            }
            printf("No solution\n");
            return 0;
        }
        printf("%f\n", -c / b);
        return 0;
    }
    double d = b * b - 4 * a * c;
    if (d < 0)
    {
        printf("No solution\n");
        return 0;
    }
    if (d == 0)
    {
        printf("%f\n", -b / (a * 2));
        return 0;
    }
    printf("%f %f\n", (-b - sqrt(d)) / (a * 2), (-b + sqrt(d)) / (a * 2));
    return 0;
}