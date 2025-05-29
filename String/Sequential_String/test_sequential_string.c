/*!
 *  \file       test_sequential_string.c
 *  \brief      Make the unit test for sequential_string
 *
 */


#include "sequential_string.h"

#include <unity_fixture.h>
#include <string.h>


TEST_GROUP(UTest4SString);

TEST_SETUP(UTest4SString)
{
}

TEST_TEAR_DOWN(UTest4SString)
{
}

TEST(UTest4SString, AssignSequentialString)
{
    char* hello_world = "Hello, C programming world.\nI am studying the data structure and algorithm.";
    SString str;
    Status status = StrAssign(str, hello_world);
    TEST_ASSERT_EQUAL(status, OK);

    StrPrint(str);
}

TEST(UTest4SString, CopySequentialStringAndCompareThem)
{
    SString source;
    StrAssign(source, "hello, world!");
    SString target;

    StrCopy(target, source);
    int result = StrCompare(source, target);
    TEST_ASSERT_EQUAL(result, 0);
}

TEST(UTest4SString, CalculateStringLength)
{
    SString str;
    char* hello_world = "Hello, world!";
    StrAssign(str, hello_world);

    int len = StrLength(str);
    TEST_ASSERT_EQUAL(len, 13);
    TEST_ASSERT_EQUAL(len, strlen(hello_world));
}

TEST(UTest4SString, ConcatenateTwoStrings)
{
    SString str1, str2;
    StrAssign(str1, "hello");
    StrAssign(str2, "world");

    SString target;
    Status status = StrConcat(target, str1, str2);
    TEST_ASSERT_EQUAL(status, true);
    TEST_ASSERT_EQUAL(strcmp((const char*)target, "helloworld"), 0);
}

TEST(UTest4SString, CheckIndex)
{
    SString src_str, sub_str;
    Status status = StrAssign(src_str, "Build finished with exit code 0");
    TEST_ASSERT_EQUAL(status, OK);
    TEST_ASSERT_EQUAL(OK, StrAssign(sub_str, "with"));

    int index = Index(src_str, sub_str, 5);
    TEST_ASSERT_EQUAL(index, 15);
}

TEST_GROUP_RUNNER(UTest4SString)
{
    RUN_TEST_CASE(UTest4SString, AssignSequentialString);
    RUN_TEST_CASE(UTest4SString, CopySequentialStringAndCompareThem);
    RUN_TEST_CASE(UTest4SString, CalculateStringLength);
    RUN_TEST_CASE(UTest4SString, ConcatenateTwoStrings);
    RUN_TEST_CASE(UTest4SString, CheckIndex);
}
