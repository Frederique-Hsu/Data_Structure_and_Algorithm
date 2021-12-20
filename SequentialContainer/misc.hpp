/*!
 *  \file   misc.hpp
 *  \brief  Declare the proptotypes
 *
 */

#pragma once

#include <iostream>

template<typename Container> void removeEveryOtherItem(Container& lst);
template<typename Container, typename ObjectType> void change(Container& container,
                                                              const ObjectType& newValue);
template<typename Container> void print(const Container& container, std::ostream& out = std::cout);


#include "misc_impl.hpp"
