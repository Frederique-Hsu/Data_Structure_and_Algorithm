/*!
 *  \file       function_pointer_issues.c
 *  \brief      
 *  
 */


#include <unity_fixture.h>

/*!
 *  \details    问题描述：
 *
 *              定义一个函数指针，指向的函数有两个int形参，并且返回一个函数指针，
 *              返回的指针指向一个有一个int形参且返回int的函数。
 */

TEST_GROUP(FunctionPointerIssues);
TEST_SETUP(FunctionPointerIssues) {}
TEST_TEAR_DOWN(FunctionPointerIssues) {}

int test(int a)
{
    a++;
    return a;
}

int (*sum_func(int a, int b))(int c)
{
    int (*pfn)(int) = test;
    
    printf("\n");
    printf("the result is %d\n", (*pfn)(a + b));

    return pfn;
}

TEST(FunctionPointerIssues, CheckNestedComplexFunctionPointer)
{
    int (*(*Fn)(int, int))(int);
    Fn = sum_func;
    int result = (*Fn)(10, 20)(50);

    TEST_ASSERT(result == 51);
}

TEST_GROUP_RUNNER(FunctionPointerIssues)
{
    RUN_TEST_CASE(FunctionPointerIssues, CheckNestedComplexFunctionPointer);
}
