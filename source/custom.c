#include <custom.h>

int printfCustom(char* fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    for (int i = 0; fmt[i] != '\0'; ++i)
    {
        if (fmt[i] == '%')
        {
            switch(fmt[++i])
            {
                case 'd':;
                    int d = va_arg(va, int);
                    printf("%d", d);
                    break;
                case 'f':;
                    double f = va_arg(va, double);
                    printf("%f", f);
                    break;
                case 's':;
                    char* s = va_arg(va, char*);
                    printf("%s", s);
                    break;
                case 'c':;
                    char c = va_arg(va, int);
                    printf("%c", c);
                    break;
                case '%':
                    printf("%%");
                    break;
                case 'l':
                    switch(fmt[++i])
                    {
                        case 'd':;
                            long int ld = va_arg(va, long int);
                            printf("%ld", ld);
                            break;
                        case 'f':;
                            double lf = va_arg(va, double);
                            printf("%lf", lf);
                            break;
                        default:
                            return 1;
                    }
                    break;
                case 'h':
                    switch(fmt[++i])
                    {
                        case 'd':;
                            short int hd = va_arg(va, int);
                            printf("%hd", hd);
                            break;
                        default:
                            return 1;
                    }
                    break;
                default:
                    return 1;
            }
        }
        else
            putchar(fmt[i]);
    }
    va_end(va);
    return 0;
}