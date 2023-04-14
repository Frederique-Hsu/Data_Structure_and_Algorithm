/*!
 *  \file   IteratorException.hpp
 *  \brief  Define the exception class for Iterator
 *
 */

#pragma once

#include <exception>
#include <iterator>

class IteratorException : public std::exception
{
public:
    IteratorException();
};

class IteratorOutOfBoundException : public IteratorException
{
public:
    IteratorOutOfBoundException();
};

class IteratorMismatchException : public IteratorException
{
public:
    IteratorMismatchException();
};
