/*!
 *  \file   utest_Square.c++
 *  \brief  Make the unit test for Square class.
 *
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include "Square.hpp"
#include "../Function_Templates/Function_Templates.hpp"

TEST(UTest4Square, CheckFindMaxSquareObject)
{
    std::vector<Square> vec = {Square{3.0}, Square(2.0), Square{2.5}};

    std::cout << "Largest square is " << findMax(vec) << std::endl;

    ASSERT_THAT(findMax(vec),  static_cast<const Square>(vec[0]));
}
