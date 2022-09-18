/*!
 *  \file   binary_search_tree_utest.c++
 *  \brief  Make the unit test for the BinarySearchTree container.
 *
 */

#include <gtest/gtest.h>

#include "binary_search_tree.hpp"

class BinarySearchTreeUTestFixture : public ::testing::Test
{
public:
    BinarySearchTree<unsigned> bst;
};

TEST_F(BinarySearchTreeUTestFixture, CheckCreateBSTInstance)
{

}
