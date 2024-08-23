#include <custom.h>

int iszero(double x) 
{
    const double EPS = 1e-6;
    return fabs(x) < EPS;
}
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
                    fputs(RED, stdout);
                    break;
                case 'D':
                    fputs(DEFAULT, stdout);
                    break;
                case 'd':
                    if (cnt_l != 0) switch (cnt_l)
                    {
                        case 1:
                            printD((long long)va_arg(va, long int));
                            break;
                        case 2:
                            printD(va_arg(va, long long));
                            break;
                        default:
                            return 1;
                    }
                    else if (cnt_h != 0) switch (cnt_h)
                    {
                        case 1:
                            printD((long long)va_arg(va, int));
                            break;
                        case 2:
                            printD((long long)va_arg(va, int));
                            break;
                        default:
                            return 1;
                    }
                    else
                        printD((long long)va_arg(va, int));
                    break;
                case 'f':
                    switch(cnt_l)
                    {
                        case 0:
                            printF(va_arg(va, double), 5);
                            break;
                        case 1:
                            printF(va_arg(va, double), 5);
                            break;
                        default:
                            return 1;
                    }
                    break;
                case 's':
                    fputs(va_arg(va, char*), stdout);
                    break;
                case 'c':
                    putchar((char)va_arg(va, int));
                    break;
                case '%':
                    putchar('%');
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
void printD(long long d)
{
    if (d == 0)
    {
        putchar('0');
        return;
    }
    if (d < 0)
    {
        putchar('-');
        d *= -1;
    }
    long long ten = 1;
    while (ten <= d)
        ten *= 10;
    ten /= 10;
    while (ten != 0)
    {
        putchar('0' + (int)(d / ten));
        d %= ten;
        ten /= 10;
    }
}
int printF(double f, int p)
{
    if (p < 0) return 1;
    if (f < 0)
    {
        putchar('-');
        f *= -1;
    }
    long long llf = (long long)f;
    printD(llf);
    if (p == 0) return 0;
    putchar('.');
    f -= llf;
    while (p-- && !iszero(f))
    {
        f *= 10;
        int intf = (int)f;
        putchar('0' + intf);
        f -= intf;
    }
    return 0;
}