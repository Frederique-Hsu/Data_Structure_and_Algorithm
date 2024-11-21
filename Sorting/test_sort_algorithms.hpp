/*!
 *  \file       test_sort_algorithms.hpp
 *  \brief      
 *  
 */


#pragma once

#include <gtest/gtest.h>

static const int DATA_ARRAY_SIZE = 20;

class UTest4SortAlgorithms : public ::testing::Test
{
public:
    virtual void SetUp() override;
    virtual void TearDown() override;
protected:
    int m_data[DATA_ARRAY_SIZE];
private:
    int generateRandomNumber();
protected:
    void displayData();
    bool isDataArraySorted();
};