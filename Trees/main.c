/*!
 *  \file       main.c
 *  \brief      
 *  
 */


#include <unity_fixture.h>


static void RunAllTests(void)
{
}


int main(int argc, char* argv[], char* envp[])
{
    printf("Current C standard no. is %ld\n", __STDC_VERSION__);
    printf("Current program is %ld-bits.\n", sizeof(void*) * 8);
    
    printf("Study the data structure and algorithms of Tree.\n");
    return UnityMain(argc, (const char**)argv, RunAllTests);
}