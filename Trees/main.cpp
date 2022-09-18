/*!
 *  \file   main.cpp
 *  \brief  In this project we will study the Tree data structure and \n
 *          some algorithms involved with Tree.
 *  \author Frederique Hsu (frederique.hsu@outlook.com)
 *  \date   Sun.    18 Sep. 2022
 *  \copyright  2022    All rights reserved.
 *
 */

#include <iostream>
#include <gtest/gtest.h>


int main(int argc, char* argv[])
{
    std::cout << "Current C++ standard no. = " << __cplusplus << std::endl;
    std::cout << "Current program is " << sizeof(void*) * 8 << "-bits.\n" << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
