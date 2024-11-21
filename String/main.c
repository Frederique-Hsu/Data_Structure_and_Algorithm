/*!
 *  \file       main.c
 *  \brief      
 *  
 */


#include <stdio.h>

#include <unity_fixture.h>

static void RunAllTests(void);

int main(int argc, char* argv[])
{
    return UnityMain(argc, (const char**)argv, RunAllTests);
}


void RunAllTests(void)
{
    RUN_TEST_GROUP(UTest4CStandard);
    RUN_TEST_GROUP(UTest4SString);
}

/*================================================================================================*/


TEST_GROUP(UTest4CStandard);

TEST_SETUP(UTest4CStandard)
{
}

TEST_TEAR_DOWN(UTest4CStandard)
{
}

TEST(UTest4CStandard, CheckCStandardNo)
{
    printf("\n");
    printf("Current C standard no. is %ld\n", __STDC_VERSION__);
    printf("Current program is %ld-bits.\n", sizeof(void*) * 8);
}

TEST_GROUP_RUNNER(UTest4CStandard)
{
    RUN_TEST_CASE(UTest4CStandard, CheckCStandardNo);
}
