/*!
 *  \file       Test_StaticLinkList.c
 *  \brief
 *
 */



#include <unity_fixture.h>

#include "StaticLinkList.h"

TEST_GROUP(UTest4StaticLinkList);

TEST_SETUP(UTest4StaticLinkList)
{
}

TEST_TEAR_DOWN(UTest4StaticLinkList)
{
}

TEST(UTest4StaticLinkList, CheckInitSLinkList)
{
    SLinkList slist;
    InitSLinkList(slist);

    DisplaySLinkList(slist);
}

TEST_GROUP_RUNNER(UTest4StaticLinkList)
{
    RUN_TEST_CASE(UTest4StaticLinkList, CheckInitSLinkList);
}
