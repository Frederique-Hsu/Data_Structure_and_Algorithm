/*!
 *  \file       check_c_standard.c
 *  \brief      Inspect the C standard no. and its compilation options.
 *  
 */


#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("Current C standard no. is: %ld\n", __STDC_VERSION__);
    printf("Current program is %ld-bits.\n", sizeof(void*) * 8);

    return 0;
}