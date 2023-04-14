/*!
 *  \file   utest_misc.c++
 *  \brief  Make the unit test for misc.
 *
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <list>
#include <ctime>
#include <cmath>
#include <iostream>
#include <chrono>

#include "misc.hpp"


class UTest4List : public ::testing::Test
{
public:
    UTest4List();
public:
    std::list<unsigned> small_list_under_test;
    std::list<unsigned> large_list_under_test;
private:
    void generateRandomList(std::list<unsigned>& lstUT, size_t amount);
};

UTest4List::UTest4List() : ::testing::Test()
{
    generateRandomList(small_list_under_test,  800000);
    generateRandomList(large_list_under_test, 1600000);
}

void UTest4List::generateRandomList(std::list<unsigned>& lstUT, size_t amount)
{
    // lstUT.resize(amount);
    std::srand(std::time(NULL));

    for (size_t num = 0; num < amount; ++num)
    {
        lstUT.push_back(std::rand() % amount);
    }
}

TEST_F(UTest4List, MeasureRemoveTimingFromSmallList)
{
    auto start = std::chrono::high_resolution_clock::now();
    removeEveryOtherItem(small_list_under_test);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =  std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "The duration is " << duration.count() << " milliseconds.\n" << std::endl;
}

TEST_F(UTest4List, MeasureRemoveTimingFromLargeList)
{
    auto start = std::chrono::high_resolution_clock::now();
    removeEveryOtherItem(large_list_under_test);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =  std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "The duration is " << duration.count() << " milliseconds.\n" << std::endl;
}

TEST(UTest4PrintFunc, ValidatePrintContainerElements)
{
    std::srand(std::time(NULL));
    const unsigned AMOUNT = 50;

    std::vector<unsigned> nums_vec;
    std::list<unsigned> nums_list;

    for (unsigned n = 0; n < AMOUNT; ++n)
    {
        nums_vec.push_back(random() % AMOUNT);
        nums_list.push_back(random() % AMOUNT);
    }

    std::cout << "Print out the vector: ";
    print(nums_vec);

    std::cout << "Print out the list: ";
    print(nums_list);
}
