/*!
 *  \file       main.c
 *  \brief      Study the list data structure and its algorithms.
 *
 */


#include <unity_fixture.h>


static void RunAllTests(void)
{
#if defined (ENABLE_SEQUENTIAL_LIST)
    RUN_TEST_GROUP(UTest4SqList);
#elif defined (ENABLE_LINKED_LIST)
    RUN_TEST_GROUP(UTest4LinkedList);
    RUN_TEST_GROUP(UTest4LinkedListWithoutHead);
    // RUN_TEST_GROUP(UTest4StaticLinkList);
    RUN_TEST_GROUP(UTest4CircularLinkedList);
#endif
}

int main(int argc, char* argv[])
{
    printf("Current C standard no. is: %ld\n", __STDC_VERSION__);
    printf("Current program is %ld-bits.\n", sizeof(void*) * 8);

    return UnityMain(argc, (const char**)argv, RunAllTests);
}
