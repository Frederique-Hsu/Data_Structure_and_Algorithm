/*!
 *  \file       test_sort_algorithms.c
 *  \brief      
 *  
 */


#include "sort_algorithms.h"

#include <unity_fixture.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "external_libs/rng/rngs.h"


TEST_GROUP(UTest4SortAlgorithms);

#define DATA_ARRAY_SIZE     20
// static const int DATA_ARRAY_SIZE = 20;
static DataType data[DATA_ARRAY_SIZE];

static void generateRandomNumbers(DataType rnds[], int size)
{
    SelectStream(0);

    static long seed;
    seed += time(NULL); // have the seed changed every time this function was called
    PutSeed(seed);

    for (int i = 0; i < size; ++i)
    {
        rnds[i] = (DataType)(Random() * pow(10, 6));
    }
}

TEST_SETUP(UTest4SortAlgorithms)
{
    generateRandomNumbers(data, DATA_ARRAY_SIZE);

    printf("\n");
    printf("%*s", 13, "Raw data:");   // 格式化输出字符串，指定长度13，+表示右对齐， -表示左对齐
    for (int index = 0; index < DATA_ARRAY_SIZE; ++index)
    {
        data[index] = data[index] % 1001;
        printf("% 5d", data[index]);
        if (index <= DATA_ARRAY_SIZE - 2)
        {
            printf(",");
        }
        else
        {
            printf("\n");
        }
    }
}

TEST_TEAR_DOWN(UTest4SortAlgorithms)
{
    printf("%*s", 13, "Sorted data:");
    for (int index = 0; index < DATA_ARRAY_SIZE; ++index)
    {
        printf("% 5d", data[index]);
        if (index <= DATA_ARRAY_SIZE - 2)
        {
            printf(",");
        }
        else
        {
            printf("\n");
        }
    }
    memset(data, 0, sizeof(DataType) * DATA_ARRAY_SIZE);
}

static bool isDataArraySorted()
{
    unsigned array_length = sizeof(data) / sizeof(data[0]);
    for (unsigned index = 0; index < array_length - 1; ++index)
    {
        if (!(data[index] <= data[index+1]))
        {
            return false;
        }
    }
    return true;
}

TEST(UTest4SortAlgorithms, Check_Insert_Sort)
{
    insert_sort(data, DATA_ARRAY_SIZE);
    TEST_ASSERT_EQUAL(isDataArraySorted(), true);
}

TEST(UTest4SortAlgorithms, Check_Select_Sort)
{
    select_sort(data, DATA_ARRAY_SIZE);
    TEST_ASSERT_EQUAL(isDataArraySorted(), true);
}

TEST(UTest4SortAlgorithms, Check_Bubble_Sort)
{
    bubble_sort(data, DATA_ARRAY_SIZE);
    TEST_ASSERT_EQUAL(isDataArraySorted(), true);
}

TEST_GROUP_RUNNER(UTest4SortAlgorithms)
{
    RUN_TEST_CASE(UTest4SortAlgorithms, Check_Insert_Sort);
    RUN_TEST_CASE(UTest4SortAlgorithms, Check_Select_Sort);
    RUN_TEST_CASE(UTest4SortAlgorithms, Check_Bubble_Sort);
}