#ifndef CUSTOM_H
#define CUSTOM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define assertCustom(expr) if (!(expr))\
{\
    printf(RED "Custom assertion falied: " #expr DEFAULT "\nFile: " __FILE__ "\nFunction: %s\n Line: %d\n", __FUNCTION__, __LINE__);\
    exit(1);\
}

int printfCustom(const char* fmt, ...);

#endif // ASSERTCUSTOM_H