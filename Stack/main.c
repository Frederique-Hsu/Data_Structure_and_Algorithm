/*!
 *  \file       main.c
 *  \brief
 *
 */


#include <stdio.h>

#include <unity_fixture.h>

static void RunAllTests(void)
{
}

int main(int argc, char* argv[])
{
    printf("Current C standard no. is %ld\n", __STDC_VERSION__);
    printf("Current C program is %ld-bits.\n", sizeof(void*) * 8);

    return UnityMain(argc, (const char**)argv, RunAllTests);
}