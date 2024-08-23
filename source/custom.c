#include <custom.h>

int printfCustom(const char* fmt, ...)
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
                    printf("%d", va_arg(va, int));
                    break;
                case 'f':;
                    printf("%f", va_arg(va, double));
                    break;
                case 's':;
                    printf("%s", va_arg(va, char*));
                    break;
                case 'c':;
                    printf("%c", (char)va_arg(va, int));
                    break;
                case '%':
                    printf("%%");
                    break;
                case 'l':
                    switch(fmt[++i])
                    {
                        case 'd':;
                            printf("%ld", va_arg(va, long int));
                            break;
                        case 'f':;
                            printf("%lf", va_arg(va, double));
                            break;
                        default:
                            return 1;
                    }
                    break;
                case 'h':
                    switch(fmt[++i])
                    {
                        case 'd':;
                            printf("%hd", (short int)va_arg(va, int));
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