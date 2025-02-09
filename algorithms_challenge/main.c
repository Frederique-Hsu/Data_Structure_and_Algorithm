/*!
 *  \file       main.c
 *  \brief      
 *  
 */


#include <unity_fixture.h>

static void runAllTests(void);

int main(int argc, char* argv[])
{
    return UnityMain(argc, (const char**)argv, runAllTests);
}

void runAllTests(void)
{
    RUN_TEST_GROUP(UTest4CStandardNo);
    RUN_TEST_GROUP(UTest4PointerIssues);
    RUN_TEST_GROUP(FunctionPointerIssues);
}

/*================================================================================================*/

TEST_GROUP(UTest4CStandardNo);

TEST_SETUP(UTest4CStandardNo)
{
}

TEST_TEAR_DOWN(UTest4CStandardNo)
{
}

TEST(UTest4CStandardNo, Check_C_StandardNo)
{
    printf("\n");
    printf("Current C standard no. is %ld\n", __STDC_VERSION__);
    printf("Current program is %ld-bits.\n", sizeof(void*) * 8);
}

TEST_GROUP_RUNNER(UTest4CStandardNo)
{
    RUN_TEST_CASE(UTest4CStandardNo, Check_C_StandardNo);
}