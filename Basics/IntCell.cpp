/*!
 *  \file   IntCell.cpp
 *  \brief  Implement the class IntCell
 *  \author Frederique Hsu
 *  \date   Sun.    05 Dec. 2021
 * 
 */

#include "IntCell.hpp"

/*!
 *  \brief  Contruct the IntCell, initial value is 0.
 */
IntCell::IntCell()
{
    storedValue = 0;
}

/*!
 *  \brief  Contruct the IntCell, initial value is the initialValue
 */
IntCell::IntCell(int initialValue)
{
    storedValue = initialValue;
}

/*!
 *  \brief  Return the stored value.
 */
int IntCell::read()
{
    return storedValue;
}

/*!
 *  \brief  Change the stored value to x.
 */
void IntCell::write(int x)
{
    storedValue = x;
}