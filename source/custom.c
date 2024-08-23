#include <custom.h>

int printfCustom(const char* fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    for (int i = 0; fmt[i] != '\0'; ++i)
    {
        if (fmt[i] == '%')
        {
            ++i;
            int cnt_l = 0, cnt_h = 0;
            while (fmt[i] == 'l')
            {
                ++i;
                ++cnt_l;
            }
            while (fmt[i] == 'h')
            {
                ++i;
                ++cnt_h;
            }
            if (cnt_l * cnt_h != 0)
                return 1;
            switch(fmt[i])
            {
                case 'R':
                    printf(RED);
                    break;
                case 'D':
                    printf(DEFAULT);
                    break;
                case 'd':
                    if (cnt_l != 0) switch (cnt_l)
                    {
                        case 1:
                            printf("%ld", va_arg(va, long int));
                            break;
                        case 2:
                            printf("%lld", va_arg(va, long long));
                            break;
                        default:
                            return 1;
                    }
                    else if (cnt_h != 0) switch (cnt_h)
                    {
                        case 1:
                            printf("%hd", (short int)va_arg(va, int));
                            break;
                        case 2:
                            printf("%hhd", (signed char)va_arg(va, int));
                            break;
                        default:
                            return 1;
                    }
                    else
                        printf("%d", va_arg(va, int));
                    break;
                case 'f':
                    switch(cnt_l)
                    {
                        case 0:
                            printf("%f", va_arg(va, double));
                            break;
                        case 1:
                            printf("%lf", va_arg(va, double));
                            break;
                        default:
                            return 1;
                    }
                    break;
                case 's':
                    printf("%s", va_arg(va, char*));
                    break;
                case 'c':
                    printf("%c", (char)va_arg(va, int));
                    break;
                case '%':
                    printf("%%");
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