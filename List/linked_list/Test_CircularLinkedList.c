/*!
 *  \file       Test_CircularLinkedList.c
 *  \brief
 *
 */


#include "CircularLinkedList.h"

#include "../../unity.test.framework/extras/fixture/unity_fixture.h"

TEST_GROUP(UTest4CircularLinkedList);

static CircularLinkedList* pcirc_list = NULL;

TEST_SETUP(UTest4CircularLinkedList)
{
    InitCircularLinkedList(&pcirc_list);
}

TEST_TEAR_DOWN(UTest4CircularLinkedList)
{
    DestroyCircularLinkedList(pcirc_list);
}

TEST(UTest4CircularLinkedList, CheckInitAndDestroyCircularLinkedList)
{
    CircularLinkedList* circ_list = NULL;
    InitCircularLinkedList(&circ_list);

    DestroyCircularLinkedList(circ_list);
}

TEST(UTest4CircularLinkedList, CheckAppendAndDisplayCircularLinkedList)
{
    AppendToCircularLinkedList(pcirc_list, 1);
    AppendToCircularLinkedList(pcirc_list, 2);
    AppendToCircularLinkedList(pcirc_list, 3);

    TEST_ASSERT_EQUAL(LengthOfCircularinkedList(pcirc_list), 3);
    DisplayCircularLinkedList(pcirc_list);

    CircularLinkedList* circ_list = NULL;
    InitCircularLinkedList(&circ_list);
    AppendToCircularLinkedList(circ_list, 4);
    AppendToCircularLinkedList(circ_list, 5);
    AppendToCircularLinkedList(circ_list, 6);
    AppendToCircularLinkedList(circ_list, 7);
    AppendToCircularLinkedList(circ_list, 8);
    AppendToCircularLinkedList(circ_list, 9);
    AppendToCircularLinkedList(circ_list, 10);

    DisplayCircularLinkedList(circ_list);

    DestroyCircularLinkedList(circ_list);
}

TEST(UTest4CircularLinkedList, CheckClearCircularLinkedList)
{
    AppendToCircularLinkedList(pcirc_list, 10);
    AppendToCircularLinkedList(pcirc_list, 20);
    AppendToCircularLinkedList(pcirc_list, 30);
    AppendToCircularLinkedList(pcirc_list, 40);
    AppendToCircularLinkedList(pcirc_list, 50);

    DisplayCircularLinkedList(pcirc_list);

    ClearCircularLinkedList(pcirc_list);
    DisplayCircularLinkedList(pcirc_list);

    /*================================================================*/

    CircularLinkedList* circ_list;
    InitCircularLinkedList(&circ_list);
    TEST_ASSERT_EQUAL(IsCircularLinkedListEmpty(circ_list), true);

    DisplayCircularLinkedList(circ_list);

    ClearCircularLinkedList(circ_list);
    DisplayCircularLinkedList(circ_list);

    AppendToCircularLinkedList(circ_list, 12345);
    DisplayCircularLinkedList(circ_list);
    TEST_ASSERT_EQUAL(IsCircularLinkedListEmpty(circ_list), false);

    DestroyCircularLinkedList(circ_list);
}

TEST(UTest4CircularLinkedList, CheckGetElemFromCircularLinkedList)
{
    AppendToCircularLinkedList(pcirc_list, 1);
    AppendToCircularLinkedList(pcirc_list, 2);
    AppendToCircularLinkedList(pcirc_list, 3);
    AppendToCircularLinkedList(pcirc_list, 4);
    AppendToCircularLinkedList(pcirc_list, 5);
    AppendToCircularLinkedList(pcirc_list, 6);
    AppendToCircularLinkedList(pcirc_list, 7);
    AppendToCircularLinkedList(pcirc_list, 8);

    DisplayCircularLinkedList(pcirc_list);

    ElemType elem;
    Status status = GetElemFromCircularLinkedList(pcirc_list, 5, &elem);
    TEST_ASSERT_EQUAL(status, OK);
    TEST_ASSERT_EQUAL_INT(elem, 5);
}

TEST(UTest4CircularLinkedList, CheckFindElemPosition)
{
    AppendToCircularLinkedList(pcirc_list, 1);
    AppendToCircularLinkedList(pcirc_list, 2);
    AppendToCircularLinkedList(pcirc_list, 3);
    AppendToCircularLinkedList(pcirc_list, 4);
    AppendToCircularLinkedList(pcirc_list, 5);
    AppendToCircularLinkedList(pcirc_list, 6);

    int position = 0;
    bool is_found = FindElemPositionFromCircularLinkedList(pcirc_list, 3, &position);
    TEST_ASSERT_EQUAL(is_found, true);
    TEST_ASSERT_EQUAL(position, 3);
}

TEST_GROUP_RUNNER(UTest4CircularLinkedList)
{
    RUN_TEST_CASE(UTest4CircularLinkedList, CheckInitAndDestroyCircularLinkedList);
    RUN_TEST_CASE(UTest4CircularLinkedList, CheckAppendAndDisplayCircularLinkedList);
    RUN_TEST_CASE(UTest4CircularLinkedList, CheckClearCircularLinkedList);
    RUN_TEST_CASE(UTest4CircularLinkedList, CheckGetElemFromCircularLinkedList);
    RUN_TEST_CASE(UTest4CircularLinkedList, CheckFindElemPosition);
}
