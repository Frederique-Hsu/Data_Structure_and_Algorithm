/*!
 *  \file   Function_Templates.hpp
 *  \brief  Define the prototypes for user-defined function templates.
 *
 */

#pragma once

/* Includes */
#include <vector>

/* Prototypes */
template<typename Comparable> const Comparable& findMax(const std::vector<Comparable>& arr);
template<typename ObjectType> const ObjectType& findMaximum(const std::vector<ObjectType>& arr);

template<typename ObjectType, typename Comparator>
const ObjectType& findMax(const std::vector<ObjectType>& arr, Comparator cmp);

template<typename ObjectType, typename Comparator>
const ObjectType& findMaximum(const std::vector<ObjectType>& arr, Comparator cmp);


/* Implementation in the below file */
#include "Function_Templates_impl.hpp"

// ASSERT_THAT(std::string("crocodile"), findMaximum<std::string, Compare
// ASSERT_THAT(std::string("crocodile"), findMaximum<std::string, Compare
