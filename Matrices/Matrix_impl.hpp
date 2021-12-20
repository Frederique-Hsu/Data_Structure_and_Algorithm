/*!
 *  \file   Matrix_impl.hpp
 *  \brief  Implement the two-dimensional array : Matrix container.
 *
 */


template<typename ElemType> Matrix<ElemType>::Matrix(int rows, int cols) : array2D(rows)
{
    for (auto& curRowArray : array2D)
    {
        curRowArray.resize(cols);
    }
}

template<typename ElemType> int Matrix<ElemType>::numrows() const
{
    return array2D.size();
}

template<typename ElemType> int Matrix<ElemType>::numcols() const
{
    return numrows() ? array2D[0].size() : 0;
}

template<typename ElemType> ElemType& Matrix<ElemType>::cell(int row, int col)
{
    assert((row < array2D.size()) && (col < array2D[0].size()));
    return (array2D[row])[col];
}

template<typename ElemType> const ElemType& Matrix<ElemType>::cell(int row, int col) const
{
    assert((row < array2D.size()) && (col < array2D[0].size()));
    return array2D[row][col];
}

template<typename ElemType> Matrix<ElemType>::Matrix(vector<vector<ElemType>> vecs) : array2D{vecs}
{
}

template<typename ElemType> Matrix<ElemType>::Matrix(vector<vector<ElemType>>&& vecs)
    : array2D{ std::move(vecs) }
{
}

template<typename ElemType> const vector<ElemType>& Matrix<ElemType>::operator[](int row) const
{
    return array2D[row];
}

template<typename ElemType> vector<ElemType>& Matrix<ElemType>::operator[](int row)
{
    return array2D[row];
}

template<typename ElemType> void copy(const Matrix<ElemType>& from, Matrix<ElemType>& to)
{
    for (int row = 0; row < to.numrows(); ++row)
    {
        to[row] = from[row];
    }
}


template<typename ElemType, size_t row, size_t column> matrix<ElemType, row, column>::matrix()
{
    for (size_t rowindex = 0; rowindex < row; ++rowindex)
    {
        for (size_t colindex = 0; colindex < column; ++colindex)
        {
            m_array2D[rowindex][colindex] = ElemType{};
        }
    }
}

template<typename ElemType, size_t row, size_t column> size_t matrix<ElemType, row, column>::numrows() const
{
    return row;
}

template<typename ElemType, size_t row, size_t column> size_t matrix<ElemType, row, column>::numcols() const
{
    return column;
}

template<typename ElemType, size_t row, size_t column> ElemType& matrix<ElemType, row, column>::cell(size_t r, size_t c)
{
    assert(r <= (row-1));
    assert(c <= (column-1));
    return m_array2D[r][c];
}

template<typename ElemType, size_t row, size_t column>
matrix<ElemType, row, column>::matrix(const matrix<ElemType, row, column>& rhs)
{
    for (size_t rowindex = 0; rowindex < row; ++rowindex)
    {
        for (size_t colindex = 0; colindex < column; ++colindex)
        {
            m_array2D[rowindex][colindex] = rhs.m_array2D[rowindex][colindex];
        }
    }
}

template<typename ElemType, size_t row, size_t column>
matrix<ElemType, row, column>& matrix<ElemType, row, column>::operator=(const matrix<ElemType, row, column>& rhs)
{
    if (this != &rhs)
    {
        for (size_t rowindex = 0; rowindex < row; ++rowindex)
        {
            for (size_t colindex = 0; colindex < column; ++colindex)
            {
                m_array2D[rowindex][colindex] = rhs.m_array2D[rowindex][colindex];
            }
        }
    }
    return *this;
}
