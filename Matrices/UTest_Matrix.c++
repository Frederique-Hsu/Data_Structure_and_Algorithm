/*!
 *  \file   UTest4_Matrix.c++
 *  \brief  Make the unit test for Matrix container.
 *
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Matrix.hpp"

TEST(UTest4Matrix, CheckCreateMatrixObject)
{
    Matrix<int> matrix(3, 4);

    ASSERT_TRUE(matrix.numrows() == 3);
    ASSERT_TRUE(matrix.numcols() == 4);

    matrix.cell(2, 3) = 15;
    ASSERT_TRUE(matrix.cell(2, 3) == 15);
    ASSERT_TRUE(matrix.cell(1, 1) == 0);
    ASSERT_TRUE(matrix[2][3] == 15);
}

TEST(UTest4matrix, Checkmatrixinstance)
{
    matrix<int, 3, 3> mat;

    ASSERT_TRUE(mat.numrows() == 3);
    ASSERT_TRUE(mat.numcols() == 3);

    for (size_t row = 0; row < mat.numrows(); ++row)
    {
        for (size_t col = 0; col < mat.numcols(); ++col)
        {
            ASSERT_TRUE(mat.cell(row, col) == 0);
        }
    }
}
