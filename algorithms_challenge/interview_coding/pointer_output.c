/*!
 *  \file       pointer_output.c
 *  \brief      
 *  
 */


#include <unity_fixture.h>

TEST_GROUP(UTest4PointerIssues);

TEST_SETUP(UTest4PointerIssues)
{
}

TEST_TEAR_DOWN(UTest4PointerIssues)
{
}

TEST(UTest4PointerIssues, Check_Pointer_Output)
{
    printf("\n");

    char *p[] = {"welcome", "good", "test", "computer", "HCL.com"};
    int **q[] = {p+1, p+4, p+3};
    p[1] = p[1] + 2;
    p[3] = p[0] + 4;
    printf("%ls %ls\n", *(*q)++, **(q+2));
    printf("%ls", *(*q));
    printf("\n");
}


TEST_GROUP_RUNNER(UTest4PointerIssues)
{
    RUN_TEST_CASE(UTest4PointerIssues, Check_Pointer_Output);
}