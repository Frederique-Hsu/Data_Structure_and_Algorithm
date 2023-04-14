/*!
 *  \file   CaseInsensitiveCompare.cpp
 *  \brief  Implement the functor class
 *
 */

#include "CaseInsensitiveCompare.hpp"

#include <string.h>
#include <strings.h>

bool CaseInsensitiveCompare::isLessThan(const std::string &lhs, const std::string &rhs) const
{
    return (strcasecmp(lhs.c_str(), rhs.c_str()) < 0);
}

bool Compare::operator()(const std::string &lhs, const std::string &rhs) const
{
    return (strcmp(lhs.c_str(), rhs.c_str()) < 0);
}
