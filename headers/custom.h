#ifndef CUSTOM_H
#define CUSTOM_H

#include <stdio.h>

#include <colors.h>

#define assertCustom(expr) if (!(expr))\
{\
    printf(RED "Custom assertion falied: " #expr DEFAULT "\nFile: " __FILE__ "\nFunction: %s\n Line: %d\n", __FUNCTION__, __LINE__);\
    exit(1);\
}


/*! \brief Checks if argument is small enough to be considered zero.
\param x double that will be compared to zero
\return nonzero if x in zero, 0 is x is not zero
 */
int iszero(double x);
void printD(long long d);
int printF(double f, int p);
int printfCustom(const char* fmt, ...);

#endif // ASSERTCUSTOM_H