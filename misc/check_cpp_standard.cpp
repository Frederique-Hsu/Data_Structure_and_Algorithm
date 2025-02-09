/*!
 *  \file       check_cpp_standard.cpp
 *  \brief      Inspect the C++ standard no. and its compilation options.
 *  
 */


#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Current C++ standard no. is: " << __cplusplus << std::endl;
    std::cout << "Current program is " << sizeof(void*) * 8 << "-bits.\n" << std::endl;

    return 0;
}