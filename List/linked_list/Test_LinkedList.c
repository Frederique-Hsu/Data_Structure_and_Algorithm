/*!
 *  \file       Test_LinkedList.c
 *  \brief
 *
 */


#include "Test_LinkedList.h"
#include "LinkedList.h"

#include <unity/unity_fixture.h>


TEST_GROUP(UTest4LinkedList);

LinkedListPtr plist_head_node = NULL;

TEST_SETUP(UTest4LinkedList)
{
    plist_head_node = InitLinkedList();
}

TEST_TEAR_DOWN(UTest4LinkedList)
{
    DestroyLinkedList(plist_head_node);
}


TEST(UTest4LinkedList, CheckInitAndDestroyLinkedList)
{
    LinkedList* plist = InitLinkedList();

    TEST_ASSERT_TRUE(plist != NULL);

    DestroyLinkedList(plist);
}

TEST(UTest4LinkedList, CheckClearLinkedList)
{
    LinkedListAppend(plist_head_node, 1);
    LinkedListAppend(plist_head_node, 2);
    LinkedListAppend(plist_head_node, 3);
    LinkedListAppend(plist_head_node, 4);
    LinkedListAppend(plist_head_node, 5);

    DisplayLinkedList(plist_head_node);

    ClearLinkedList(plist_head_node);

    DisplayLinkedList(plist_head_node);

    TEST_ASSERT_EQUAL(IsLinkedListEmpty(plist_head_node), true);
}

TEST(UTest4LinkedList, CheckLinkedListAppend)
{
    LinkedListAppend(plist_head_node, 1);

    TEST_ASSERT_EQUAL(IsLinkedListEmpty(plist_head_node), false);

    LinkedListAppend(plist_head_node, 2);
    LinkedListAppend(plist_head_node, 3);

    TEST_ASSERT_EQUAL(LinkedListLength(plist_head_node), 3);

    DisplayLinkedList(plist_head_node);
}

TEST(UTest4LinkedList, CheckGetElem)
{
    LinkedListAppend(plist_head_node, 10);
    LinkedListAppend(plist_head_node, 20);
    LinkedListAppend(plist_head_node, 30);
    LinkedListAppend(plist_head_node, 40);
    LinkedListAppend(plist_head_node, 50);
    LinkedListAppend(plist_head_node, 60);

    ElemType elem;
    Status status = GetLinkedListElem(plist_head_node, 4, &elem);
    TEST_ASSERT_EQUAL(status, OK);
    TEST_ASSERT_EQUAL(elem, 40);

    TEST_ASSERT_EQUAL(GetLinkedListElem(plist_head_node, 6, &elem), OK);
    TEST_ASSERT_EQUAL_INT(elem, 60);
}

bool equal(ElemType a, ElemType b)
{
    return (a == b);
}

TEST(UTest4LinkedList, CheckLocateElem)
{
    LinkedListAppend(plist_head_node, -5);
    LinkedListAppend(plist_head_node, -4);
    LinkedListAppend(plist_head_node, -3);
    LinkedListAppend(plist_head_node, -2);
    LinkedListAppend(plist_head_node, -1);
    LinkedListAppend(plist_head_node, 0);
    LinkedListAppend(plist_head_node, 1);
    LinkedListAppend(plist_head_node, 2);
    LinkedListAppend(plist_head_node, 3);

    int index = LocateLinkedListElement(plist_head_node, 0, equal);
    TEST_ASSERT_EQUAL(index, 6);

    DisplayLinkedList(plist_head_node);

    TEST_ASSERT_EQUAL(LocateLinkedListElement(plist_head_node, -5, equal), 1);
    TEST_ASSERT_EQUAL(LocateLinkedListElement(plist_head_node, 3, equal), 9);
}

TEST(UTest4LinkedList, CheckPriorElemAndNextElem)
{
    LinkedListAppend(plist_head_node, 1);
    LinkedListAppend(plist_head_node, 1);
    LinkedListAppend(plist_head_node, 2);
    LinkedListAppend(plist_head_node, 3);
    LinkedListAppend(plist_head_node, 5);
    LinkedListAppend(plist_head_node, 8);
    LinkedListAppend(plist_head_node, 13);
    LinkedListAppend(plist_head_node, 21);
    LinkedListAppend(plist_head_node, 34);
    LinkedListAppend(plist_head_node, 55);

    ElemType prior_elem = 0, next_elem = 0;
    Status status = LinkedListPriorElem(plist_head_node, 13, &prior_elem);
    TEST_ASSERT_EQUAL(status, OK);
    TEST_ASSERT_EQUAL(prior_elem, 8);

    status = LinkedListNextElem(plist_head_node, 21, &next_elem);
    TEST_ASSERT_EQUAL(status, OK);
    TEST_ASSERT_EQUAL(next_elem, 34);

    DisplayLinkedList(plist_head_node);
}

TEST(UTest4LinkedList, CheckInsertIntoList)
{
    LinkedListAppend(plist_head_node, 10);
    LinkedListAppend(plist_head_node, 20);
    LinkedListAppend(plist_head_node, 30);
    LinkedListAppend(plist_head_node, 40);
    LinkedListAppend(plist_head_node, 50);

    DisplayLinkedList(plist_head_node);

    LinkedListInsert(plist_head_node, 4, 125);
    TEST_ASSERT_EQUAL(LinkedListLength(plist_head_node), 6);

    DisplayLinkedList(plist_head_node);

    LinkedListInsert(plist_head_node, 1, -85);
    LinkedListInsert(plist_head_node, 7, 1024);
    DisplayLinkedList(plist_head_node);

    TEST_ASSERT_EQUAL(LinkedListLength(plist_head_node), 8);
}

TEST(UTest4LinkedList, CheckDeleteFromList)
{
    LinkedListAppend(plist_head_node, 1);
    LinkedListAppend(plist_head_node, 2);
    LinkedListAppend(plist_head_node, -3);
    LinkedListAppend(plist_head_node, 4);
    LinkedListAppend(plist_head_node, -5);
    LinkedListAppend(plist_head_node, -6);
    LinkedListAppend(plist_head_node, 7);
    DisplayLinkedList(plist_head_node);

    ElemType elem = 0;
    Status status = LinkedListDelete(plist_head_node, 3, &elem);
    TEST_ASSERT_EQUAL(status, OK);
    TEST_ASSERT_EQUAL_INT(elem, -3);
    TEST_ASSERT_EQUAL(LinkedListLength(plist_head_node), 6);

    DisplayLinkedList(plist_head_node);

    TEST_ASSERT_EQUAL(LinkedListDelete(plist_head_node, 4, &elem), OK);
    TEST_ASSERT_EQUAL(LinkedListDelete(plist_head_node, 4, &elem), OK);
    TEST_ASSERT_EQUAL(LinkedListLength(plist_head_node), 4);

    DisplayLinkedList(plist_head_node);
}

void printNode(ElemType elem)
{
    printf("current node's data is: %d\n", elem);
}

TEST(UTest4LinkedList, CheckTraverseLinkedList)
{
    LinkedListAppend(plist_head_node, 12);
    LinkedListAppend(plist_head_node, 34);
    LinkedListAppend(plist_head_node, 56);
    LinkedListAppend(plist_head_node, 78);
    LinkedListAppend(plist_head_node, 90);
    LinkedListAppend(plist_head_node, -100);
    LinkedListAppend(plist_head_node, 250);
    LinkedListAppend(plist_head_node, -360);

    DisplayLinkedList(plist_head_node);

    LinkedListTraverse(plist_head_node, printNode);

}

IGNORE_TEST(UTest4LinkedList, CheckCreateLinkedListReverseOrder)
{
    LinkedList* reverse_list = NULL;
    CreateLinkedListReverseOrder(&reverse_list, 5);

    DisplayLinkedList(reverse_list);
    TEST_ASSERT_EQUAL(LinkedListLength(reverse_list), 5);

    DestroyLinkedList(reverse_list);
}

IGNORE_TEST(UTest4LinkedList, CheckCreateLinkedListPositiveOrder)
{
    LinkedList* positive_list = NULL;
    CreateLinkedListPositiveOrder(&positive_list, 8);

    DisplayLinkedList(positive_list);
    TEST_ASSERT_EQUAL(LinkedListLength(positive_list), 8);

    DestroyLinkedList(positive_list);
}

static bool le(ElemType a, ElemType b)
{
    return (a <= b);
}

TEST(UTest4LinkedList, CheckMergeTwoLinkedLists)
{
    LinkedList* a = InitLinkedList();
    LinkedListAppend(a, 24);
    LinkedListAppend(a, 45);
    LinkedListAppend(a, -30);
    LinkedListAppend(a, 58);
    LinkedListInsert(a, 4, 750);
    int len_a = LinkedListLength(a);

    LinkedList* b = InitLinkedList();
    LinkedListAppend(b, -82);
    LinkedListAppend(b, 123);
    LinkedListAppend(b, 480);
    LinkedListInsert(b, 2, -360);
    LinkedListAppend(b, -58);
    LinkedListInsert(b, 3, 666);
    int len_b = LinkedListLength(b);

    DisplayLinkedList(a);
    DisplayLinkedList(b);

    LinkedList* c = InitLinkedList();
    MergeTwoLinkedLists(a, b, c, le);
    int len_c = LinkedListLength(c);

    DisplayLinkedList(c);

    TEST_ASSERT_EQUAL(len_a + len_b, len_c);

    DestroyLinkedList(c);
}

TEST_GROUP_RUNNER(UTest4LinkedList)
{
    RUN_TEST_CASE(UTest4LinkedList, CheckInitAndDestroyLinkedList);
    RUN_TEST_CASE(UTest4LinkedList, CheckLinkedListAppend);
    RUN_TEST_CASE(UTest4LinkedList, CheckGetElem);
    RUN_TEST_CASE(UTest4LinkedList, CheckLocateElem);
    RUN_TEST_CASE(UTest4LinkedList, CheckPriorElemAndNextElem);
    RUN_TEST_CASE(UTest4LinkedList, CheckClearLinkedList);
    RUN_TEST_CASE(UTest4LinkedList, CheckInsertIntoList);
    RUN_TEST_CASE(UTest4LinkedList, CheckDeleteFromList);
    RUN_TEST_CASE(UTest4LinkedList, CheckTraverseLinkedList);
    RUN_TEST_CASE(UTest4LinkedList, CheckCreateLinkedListReverseOrder);
    RUN_TEST_CASE(UTest4LinkedList, CheckCreateLinkedListPositiveOrder);
    RUN_TEST_CASE(UTest4LinkedList, CheckMergeTwoLinkedLists);
}

/*================================================================================================*/

TEST_GROUP(UTest4LinkedListWithoutHead);

static LinkedList* plist = NULL;

TEST_SETUP(UTest4LinkedListWithoutHead)
{
    CreateLinkedListWithoutHead(&plist, 15);
}

TEST_TEAR_DOWN(UTest4LinkedListWithoutHead)
{
    DestroyLinkedListWithoutHead(plist);
}

TEST(UTest4LinkedListWithoutHead, CheckCreateLinkedList)
{
    LinkedList* list = NULL;

    CreateLinkedListWithoutHead(&list, 25);
    TEST_ASSERT_EQUAL(LengthOfLinkedListWithoutHead(list), 1);

    DestroyLinkedListWithoutHead(list);
}

TEST(UTest4LinkedListWithoutHead, CheckAppendToLinkedListWithoutHead)
{
    AppendToLinkedListWithoutHead(plist, 20);
    AppendToLinkedListWithoutHead(plist, -80);
    AppendToLinkedListWithoutHead(plist, 125);

    TEST_ASSERT_EQUAL(LengthOfLinkedListWithoutHead(plist), 4);
}

TEST(UTest4LinkedListWithoutHead, CheckGetElemFromLinkedListWithoutHead)
{
    AppendToLinkedListWithoutHead(plist, 1);
    AppendToLinkedListWithoutHead(plist, 2);
    AppendToLinkedListWithoutHead(plist, 3);
    AppendToLinkedListWithoutHead(plist, 4);
    AppendToLinkedListWithoutHead(plist, 5);
    AppendToLinkedListWithoutHead(plist, 6);

    TEST_ASSERT_EQUAL(LengthOfLinkedListWithoutHead(plist), 7);

    DisplayLinkedListWithoutHead(plist);

    ElemType elem = 0;
    Status status = GetElemFromLinkedListWithoutHead(plist, 3, &elem);
    TEST_ASSERT_EQUAL(status, OK);
    TEST_ASSERT_EQUAL_INT(elem, 2);

    TEST_ASSERT_EQUAL(GetElemFromLinkedListWithoutHead(plist, 1, &elem), OK);
    TEST_ASSERT_EQUAL(elem, 15);

    TEST_ASSERT_EQUAL(GetElemFromLinkedListWithoutHead(plist,
                                                       LengthOfLinkedListWithoutHead(plist),
                                                       &elem),
                      OK);
    TEST_ASSERT_EQUAL(elem, 6);
}

TEST(UTest4LinkedListWithoutHead, CheckInsertIntoLinkedList)
{
    LinkedList* list = NULL;

    CreateLinkedListWithoutHead(&list, 15);
    AppendToLinkedListWithoutHead(list, 1);
    AppendToLinkedListWithoutHead(list, 2);
    AppendToLinkedListWithoutHead(list, 3);
    AppendToLinkedListWithoutHead(list, 4);
    AppendToLinkedListWithoutHead(list, 5);
    AppendToLinkedListWithoutHead(list, 6);

    int origin_len = LengthOfLinkedListWithoutHead(list);

    DisplayLinkedListWithoutHead(list);

    TEST_ASSERT_EQUAL(InsertIntoLinkedListWithoutHead(&list, 2, -10), OK);
    TEST_ASSERT_EQUAL(LengthOfLinkedListWithoutHead(list), origin_len+1);

    DisplayLinkedListWithoutHead(list);

    TEST_ASSERT_EQUAL(OK, InsertIntoLinkedListWithoutHead(&list, 1, 120));
    InsertIntoLinkedListWithoutHead(&list, LengthOfLinkedListWithoutHead(list), -200);

    DisplayLinkedListWithoutHead(list);

    DestroyLinkedListWithoutHead(list);
}

TEST(UTest4LinkedListWithoutHead, CheckDeleteFromLinkedList)
{
    LinkedList* list = NULL;
    CreateLinkedListWithoutHead(&list, 15);

    AppendToLinkedListWithoutHead(list, 10);
    AppendToLinkedListWithoutHead(list, 20);
    AppendToLinkedListWithoutHead(list, 30);
    AppendToLinkedListWithoutHead(list, 40);
    AppendToLinkedListWithoutHead(list, 50);
    DisplayLinkedListWithoutHead(list);

    int origin_len = LengthOfLinkedListWithoutHead(list);

    ElemType elem = 0;
    TEST_ASSERT_EQUAL(OK, DeleteFromLinkedListWithoutHead(&list, 3, &elem));
    TEST_ASSERT_EQUAL(elem, 20);
    TEST_ASSERT_EQUAL(LengthOfLinkedListWithoutHead(list), origin_len-1);

    DisplayLinkedListWithoutHead(list);

    DeleteFromLinkedListWithoutHead(&list, 1, &elem);
    DisplayLinkedListWithoutHead(list);

    int len = LengthOfLinkedListWithoutHead(list);
    DeleteFromLinkedListWithoutHead(&list, len, &elem);

    DisplayLinkedListWithoutHead(list);

    DestroyLinkedListWithoutHead(list);
}

TEST_GROUP_RUNNER(UTest4LinkedListWithoutHead)
{
    RUN_TEST_CASE(UTest4LinkedListWithoutHead, CheckCreateLinkedList);
    RUN_TEST_CASE(UTest4LinkedListWithoutHead, CheckAppendToLinkedListWithoutHead);
    RUN_TEST_CASE(UTest4LinkedListWithoutHead, CheckGetElemFromLinkedListWithoutHead);
    RUN_TEST_CASE(UTest4LinkedListWithoutHead, CheckInsertIntoLinkedList);
    RUN_TEST_CASE(UTest4LinkedListWithoutHead, CheckDeleteFromLinkedList);
}
