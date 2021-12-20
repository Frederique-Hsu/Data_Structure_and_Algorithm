/*!
 *  \file   Matrix.hpp
 *  \brief  Define a container with two-dimensional array
 *
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP

    #include <vector>

    using namespace std;

    template<typename ElemType> class Matrix
    {
    public:
        Matrix(int rows, int cols);
        Matrix(vector<vector<ElemType>> vecs);
        Matrix(vector<vector<ElemType>>&& vecs);
    private:
        vector<vector<ElemType>> array2D;
    public:
        const vector<ElemType>& operator[](int row) const;
        vector<ElemType>& operator[](int row);
        const ElemType& cell(int row, int col) const;
        ElemType& cell(int row, int col);

        int numrows() const;
        int numcols() const;
    };

    template<typename ElemType> void copy(const Matrix<ElemType>& from, Matrix<ElemType>& to);

    template<typename ElemType, size_t row, size_t column> class matrix
    {
    public:
        matrix();
        matrix(const matrix<ElemType, row, column>& rhs);
        matrix& operator=(const matrix<ElemType, row, column>& rhs);
    private:
        matrix(matrix<ElemType, row, column>&&) = delete;
        matrix& operator=(matrix<ElemType, row, column>&&) = delete;
    private:
        ElemType m_array2D[row][column];
    public:
        size_t numrows() const;
        size_t numcols() const;
        ElemType& cell(size_t r, size_t c);
        const ElemType& cell(size_t r, size_t c) const;
    };

    #include "Matrix_impl.hpp"

#endif  /* MATRIX_HPP */
