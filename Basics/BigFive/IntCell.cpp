/*!
 *  \file   IntCell.cpp
 *  \brief  Implement the class IntCell
 *  \author Frederique Hsu
 *  \date   Sun.    05 Dec. 2021
 * 
 */

#include "IntCell.hpp"

#include <iostream>

/*!
 *  \brief  Contruct the IntCell, initial value is 0.
 */
IntCell::IntCell()
{
    storedValue = nullptr;
}

/*!
 *  \brief  Contruct the IntCell, initial value is the initialValue
 */
IntCell::IntCell(int initialValue)
{
    storedValue = new int{initialValue};
}

IntCell::~IntCell()
{
#if defined (DEBUG)
    std::cout << "Invoking IntCell::~IntCell() destructor." << std::endl;
#endif
    delete storedValue;
}

IntCell::IntCell(const IntCell& rhs)
{
    storedValue = new int{ *(rhs.storedValue) };
}

IntCell::IntCell(IntCell&& rhs) : storedValue(rhs.storedValue)
{
    rhs.storedValue = nullptr;
}

IntCell& IntCell::operator=(const IntCell& rhs)
{
    if (this != &rhs)
    {
        *storedValue = *(rhs.storedValue);  /*! \note this must assign the value, not assign the pointer. */
    }
    return *this;
}

IntCell& IntCell::operator=(IntCell&& rhs)
{
    std::swap(storedValue, rhs.storedValue);
    return *this;
}

/*!
 *  \brief  Return the stored value.
 */
int IntCell::read() const
{
    return *storedValue;
}

/*!
 *  \brief  Change the stored value to x.
 */
void IntCell::write(int x)
{
    *storedValue = x;
}

