#ifndef ASSERTCUSTOM_H
#define ASSERTCUSTOM_H
#include <stdlib.h>

#define assertCustom(expr) if (!(expr))\
{\
    printf(RED "Custom assertion falied: " #expr DEFAULT "\nFile: " __FILE__ "\nFunction: %s\n Line: %d\n", __FUNCTION__, __LINE__);\
    exit(1);\
}

#endif // ASSERTCUSTOM_H