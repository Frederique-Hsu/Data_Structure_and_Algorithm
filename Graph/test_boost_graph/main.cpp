/*!
 *  \file       main.cpp
 *  \brief      
 *  
 */


#define BOOST_TEST_MODULE   "unit test for boost graph application."

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_NO_MAIN

#include <boost/test/unit_test.hpp>

#if defined (BOOST_TEST_DYN_LINK) && defined (BOOST_TEST_NO_MAIN)
    #include <boost/test/impl/unit_test_main.ipp>
    #include <boost/test/impl/framework.ipp>

    int main(int argc, char* argv[])
    {
        return boost::unit_test::unit_test_main(&init_unit_test, argc, argv);
    }
#else
    #pragma message "Use the static link to libboost_unit_test_framework.a, and the library-inherent main() function"
#endif

BOOST_AUTO_TEST_CASE(CheckCppStandardNo)
{
    std::cout << "Current C++ standard no. is " << __cplusplus << std::endl;
    std::cout << "Current program is " << sizeof(void*) * 8 << "-bits.\n" << std::endl;

    BOOST_CHECK(true);
}