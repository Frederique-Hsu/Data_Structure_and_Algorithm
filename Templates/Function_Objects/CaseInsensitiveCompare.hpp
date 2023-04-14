/*!
 *  \file   CaseInsensitiveCompare.hpp
 *  \brief  Define a functor class.
 *
 */


#pragma once

#include <string>

class CaseInsensitiveCompare
{
public:
    bool isLessThan(const std::string& lhs, const std::string& rhs) const;
};

class Compare
{
public:
    bool operator()(const std::string& lhs, const std::string& rhs) const;
};
