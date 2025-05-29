/*!
 *  \file       Test_SqList.c
 *  \brief
 *
 */


#include "SqList.h"

#include <unity_fixture.h>

TEST_GROUP(UTest4SqList);

static SqList list;

TEST_SETUP(UTest4SqList)
{
    InitList(&list);

    TEST_ASSERT_TRUE(list.elem != NULL);
    TEST_ASSERT_TRUE(IsListEmpty(list));
    TEST_ASSERT_EQUAL(list.listsize, LIST_INIT_SIZE);
}

TEST_TEAR_DOWN(UTest4SqList)
{
    DestroyList(&list);

    TEST_ASSERT_TRUE(list.elem == NULL);
    TEST_ASSERT_EQUAL(list.length, 0);
}

TEST(UTest4SqList, CheckInitializeAndDestroySqList)
{
    SqList list;

    InitList(&list);
    TEST_ASSERT_EQUAL(list.length, 0);
    TEST_ASSERT_EQUAL(list.listsize, LIST_INIT_SIZE);
    TEST_ASSERT_TRUE(list.elem != NULL);

    int elements_total_size = sizeof(list.elem);
    int element_unit_size = sizeof(list.elem[0]);
    [[maybe_unused]] int element_array_length = elements_total_size / element_unit_size;

    DestroyList(&list);
    TEST_ASSERT_TRUE(list.elem == NULL);
    TEST_ASSERT_EQUAL(list.length, 0);
}

TEST(UTest4SqList, CheckListAppend)
{
    ListAppend(&list, 35);
    TEST_ASSERT_EQUAL(list.length, 1);

    ListAppend(&list, -80);
    ListAppend(&list, 12);
    ListAppend(&list, 52);
    ListAppend(&list, -48);

    TEST_ASSERT_EQUAL(list.length, 5);
    TEST_ASSERT_EQUAL(list.listsize, LIST_INIT_SIZE);

    Display(list);
}

TEST(UTest4SqList, CheckAppend10MoreElementsIntoList)
{
    ListAppend(&list, 1);
    ListAppend(&list, 2);
    ListAppend(&list, 3);
    ListAppend(&list, 4);
    ListAppend(&list, 5);
    ListAppend(&list, 6);
    ListAppend(&list, 7);
    ListAppend(&list, 8);
    ListAppend(&list, 9);
    ListAppend(&list, 10);

    TEST_ASSERT_EQUAL(list.length, 10);

    ListAppend(&list, 11);
    TEST_ASSERT_EQUAL(list.listsize, LIST_INIT_SIZE + LIST_INCREMENT);

    ListAppend(&list, 12);
    ListAppend(&list, 13);
    TEST_ASSERT_EQUAL(ListLength(list), 13);
    TEST_ASSERT_EQUAL(list.listsize, 14);

    ListAppend(&list, 14);
    ListAppend(&list, 15);
    ListAppend(&list, 16);
    ListAppend(&list, 17);
    ListAppend(&list, 18);

    TEST_ASSERT_EQUAL(ListLength(list), 18);
    TEST_ASSERT_EQUAL(list.listsize, 18);

    Display(list);
}

static void print(ElemType elem)
{
    printf("current element is %d\n", elem);
}

static bool equal(ElemType a, ElemType b)
{
    return (a == b);
}

TEST(UTest4SqList, CheckGetElemPriorElemNextElemAndTraverseList)
{
    ListAppend(&list, 10);
    ListAppend(&list, 20);
    ListAppend(&list, 30);
    ListAppend(&list, 40);
    ListAppend(&list, 50);
    ListAppend(&list, 60);
    ListAppend(&list, 70);
    ListAppend(&list, 80);
    ListAppend(&list, 90);
    ListAppend(&list, 100);

    printf("\n");
    ListTraverse(list, print);

    ElemType elem = 0;
    TEST_ASSERT_EQUAL(GetElem(list, 4, &elem), OK);
    TEST_ASSERT_EQUAL_INT(elem, 40);

    ElemType prio_elem = 0, next_elem = 0;
    TEST_ASSERT_EQUAL(PriorElem(list, 70, &prio_elem), OK);
    TEST_ASSERT_EQUAL(prio_elem, 60);
    TEST_ASSERT_EQUAL(NextElem(list, 70, &next_elem), OK);
    TEST_ASSERT_EQUAL_INT(next_elem, 80);

    int index = LocateElem(list, 50, equal);
    TEST_ASSERT_EQUAL(index, 5);
    index = LocateElem(list, 6, equal);
    TEST_ASSERT_EQUAL(index, 0);
}

TEST(UTest4SqList, CheckListInsertAndDelete)
{
    ListAppend(&list, 10);
    ListAppend(&list, 20);
    ListAppend(&list, 30);
    ListAppend(&list, 40);
    ListAppend(&list, 50);
    ListAppend(&list, 60);
    ListAppend(&list, 70);
    ListAppend(&list, 80);
    ListAppend(&list, 90);
    ListAppend(&list, 100);

    Status status = ListInsert(&list, 4, 1234);
    TEST_ASSERT_EQUAL(status, OK);
    Display(list);

    ElemType elem;
    TEST_ASSERT_EQUAL(GetElem(list, 4, &elem), OK);
    TEST_ASSERT_EQUAL_INT(elem, 1234);

    ListInsert(&list, 6, 1024);
    ListInsert(&list, 3, 2048);
    ListInsert(&list, 10, -520);
    ListInsert(&list, 9, -256);

    Display(list);

    TEST_ASSERT_EQUAL(ListDelete(&list, 3, &elem), OK);
    TEST_ASSERT_EQUAL(elem, 30);
    TEST_ASSERT_EQUAL(list.length, 14);

    ListDelete(&list, 7, &elem);
    TEST_ASSERT_EQUAL(list.length, 13);
    TEST_ASSERT_EQUAL(list.listsize, 16);

    Display(list);
}

TEST_GROUP_RUNNER(UTest4SqList)
{
    RUN_TEST_CASE(UTest4SqList, CheckInitializeAndDestroySqList);
    RUN_TEST_CASE(UTest4SqList, CheckListAppend);
    RUN_TEST_CASE(UTest4SqList, CheckAppend10MoreElementsIntoList);
    RUN_TEST_CASE(UTest4SqList, CheckGetElemPriorElemNextElemAndTraverseList);
    RUN_TEST_CASE(UTest4SqList, CheckListInsertAndDelete);
}
