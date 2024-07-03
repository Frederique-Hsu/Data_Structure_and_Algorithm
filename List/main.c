/*!
 *  \file       main.c
 *  \brief      Study the list data structure and its algorithms.
 *
 */


#include "../unity.test.framework/extras/fixture/unity_fixture.h"


static void RunAllTests(void)
{
    RUN_TEST_GROUP(UTest4SqList);
    RUN_TEST_GROUP(UTest4LinkedList);
    RUN_TEST_GROUP(UTest4LinkedListWithoutHead);
}

int main(int argc, char* argv[])
{
    return UnityMain(argc, (const char**)argv, RunAllTests);
}
