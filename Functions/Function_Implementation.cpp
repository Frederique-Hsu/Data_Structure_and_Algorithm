#include "Function_Prototype.h"
#include <cstdlib>

int gcd(int v1, int v2)
{
    while (v2)
    {
        int temp = v2;
        v2 = v1 % v2;
        v1 = temp;
    }
    return v1;
}

void process(void)      /* equivalent to void process() */
{
}

void reset(int *ip)
{
    *ip = 0;    /* change the value of the object to which ip points */
    ip = 0;     /* change only the local value of ip; the argument is unchanged */
}

#if !defined (REFERENCE_PARAMETERS)
void swap(int v1, int v2)
{
    int temp = v2;
    v2 = v1;        /* assigns new value to local copy of the argument */
    v1 = temp;
}       /* local objects v1 and v2, no longer exist */
#else
#endif
