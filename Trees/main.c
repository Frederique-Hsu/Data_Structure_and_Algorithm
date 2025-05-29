/*!
 *  \file       main.c
 *  \brief      
 *  
 */


#include <unity_fixture.h>


static void RunAllTests(void);

int main(int argc, char* argv[], char* envp[])
{
    (void)envp;
    
    printf("Study the data structure and algorithms of Tree.\n");
    return UnityMain(argc, (const char**)argv, RunAllTests);
}

void RunAllTests(void)
{
    RUN_TEST_GROUP(UTest4CStandardProgram);
}

/*============================================================================*/

TEST_GROUP(UTest4CStandardProgram);
TEST_SETUP(UTest4CStandardProgram) {}
TEST_TEAR_DOWN(UTest4CStandardProgram) {}

TEST(UTest4CStandardProgram, CheckCStandardNo)
{
    printf("\n");
    printf("Current C standard no. is %ld\n", __STDC_VERSION__);
    printf("Current program is %ld-bits.\n", sizeof(void*) * 8);
    printf("\n");
}

TEST_GROUP_RUNNER(UTest4CStandardProgram)
{
    RUN_TEST_CASE(UTest4CStandardProgram, CheckCStandardNo);
}