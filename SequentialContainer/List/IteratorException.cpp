/*!
 *  \file   IteratorException.cpp
 *  \brief  Implement the exception class for Iterator
 *
 */

#include "IteratorException.hpp"

IteratorException::IteratorException() : std::exception()
{
}

IteratorOutOfBoundException::IteratorOutOfBoundException() : IteratorException()
{
}

IteratorMismatchException::IteratorMismatchException() : IteratorException()
{
}
