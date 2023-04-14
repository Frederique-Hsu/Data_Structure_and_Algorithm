/*!
 *  \file   main.cpp
 *  \brief  In this project, we will study how the C++ templates work.
 *  \author Frederique Hsu (frederique.hsu@outlook.com)
 *  \date   Sun.    12 Dec. 2021
 *
 */


#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
