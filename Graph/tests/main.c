/*!
 *  \file       main.c
 *  \brief      
 *  
 */


#include <stdio.h>

#include <unity_fixture.h>

static void runAllTests(void);

int main(int argc, char* argv[])
{
    return UnityMain(argc, (const char**)argv, runAllTests);
}

void runAllTests(void)
{
    RUN_TEST_GROUP(UTest4CStandard);
    RUN_TEST_GROUP(UTest4GraphAdjacentMatrix);
}



TEST_GROUP(UTest4CStandard);

TEST_SETUP(UTest4CStandard) {}
TEST_TEAR_DOWN(UTest4CStandard) {}

TEST(UTest4CStandard, CheckCStandardNo)
{
    printf("\n");
    printf("Current C standard no. is %ld\n", __STDC_VERSION__);
    printf("Current program is %ld-bits.", sizeof(void*) * 8);
    printf("\n");
}

TEST_GROUP_RUNNER(UTest4CStandard)
{
    RUN_TEST_CASE(UTest4CStandard, CheckCStandardNo);
}