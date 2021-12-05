/*!
 *  \file   IntCell.hpp
 *  \brief  Define the class IntCell
 *  \author Frederique Hsu
 *  \date   Sun.    05 Dec. 2021
 * 
 */

#ifndef INT_CELL_HPP
#define INT_CELL_HPP

    /*!
     *  \class  IntCell
     *  \brief  A class for simulating an integer memory cell.
     */
    class IntCell
    {
    public:
        IntCell();
        explicit IntCell(int initialValue = 0);
    public:
        int read() const;
        void write(int x);
    private:
        int storedValue;
    };

#endif  /* INT_CELL_HPP */
