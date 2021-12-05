/*!
 *  \file   main.cpp
 *  \brief  Study some basic knowledge of C++ class as the preparation.
 *  \author Frederique Hsu
 *  \date   Sun.    05 Dec. 2021
 * 
 */

#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char* argv[])
{
    std::cout << "Current C++ standard no. = " << __cplusplus << std::endl;
    std::cout << "Current program is " << sizeof(void*) * 8 << "-bits\n" << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}