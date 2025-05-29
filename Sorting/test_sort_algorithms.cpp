/*!
 *  \file       test_sort_algorithms.cpp
 *  \brief      
 *  
 */


#include "test_sort_algorithms.hpp"

#include "sort_algorithms.hpp"
#include "sort_algorithms.cpp"

#include <random>
#include <iomanip>

void UTest4SortAlgorithms::SetUp()
{
    for (int index = 0; index < sizeof(m_data)/sizeof(m_data[0]); ++index)
    {
        m_data[index] = generateRandomNumber();
    }

    std::cout << std::setw(13) << std::right << "Raw data: ";
    displayData();
}

void UTest4SortAlgorithms::TearDown()
{
    std::cout << std::right << "Sorted data: ";
    displayData();
}

int UTest4SortAlgorithms::generateRandomNumber()
{
    int min = -1000, max = 1000;
    std::random_device seed;
    std::ranlux48 engine(seed());
    std::uniform_int_distribution<> distribution(min, max);
    int random_number = distribution(engine);
    return random_number;
}

void UTest4SortAlgorithms::displayData()
{
    int index;
    for (index = 0; index < sizeof(m_data)/sizeof(m_data[0]) - 1; ++index)
    {
        std::cout << std::setw(5) << std::right << m_data[index] << ", ";
    }
    std::cout << std::setw(5) << std::right << m_data[index] << std::endl;
}

bool UTest4SortAlgorithms::isDataArraySorted()
{
    for (unsigned index = 0U; index < sizeof(m_data)/sizeof(m_data[0]) - 1; ++index)
    {
        if (!(m_data[index] <= m_data[index+1]))
        {
            return false;
        }
    }
    return true;
}

TEST_F(UTest4SortAlgorithms, Check_Insert_Sort)
{
    insert_sort(m_data, sizeof(m_data)/sizeof(m_data[0])); 
    EXPECT_EQ(isDataArraySorted(), true)  ;
}

TEST_F(UTest4SortAlgorithms, Check_Select_Sort)
{
    select_sort(m_data, sizeof(m_data)/sizeof(m_data[0]));
    EXPECT_EQ(isDataArraySorted(), true);
}

TEST_F(UTest4SortAlgorithms, Check_Bubble_Sort)
{
    bubble_sort(m_data, sizeof(m_data)/sizeof(m_data[0]));
    EXPECT_EQ(isDataArraySorted(), true);
}

TEST_F(UTest4SortAlgorithms, Check_Improved_Bubble_Sort)
{
    improved_bubble_sort(m_data, sizeof(m_data)/sizeof(m_data[0]));
    EXPECT_EQ(isDataArraySorted(), true);
}

TEST_F(UTest4SortAlgorithms, Check_Comb_Sort)
{
    comb_sort(m_data, sizeof(m_data)/sizeof(m_data[0]));
    EXPECT_EQ(isDataArraySorted(), true);
}