/*!
 *  \file       main.cpp
 *  \brief      Study the data structure of tree.
 *
 */


#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Current C++ standard No. is: " << __cplusplus << std::endl;
    std::cout << "Current program is " << sizeof(void*) * 8 << "-bits.\n" << std::endl;

    std::cout << "Study the data structure and algorithms of tree." << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
