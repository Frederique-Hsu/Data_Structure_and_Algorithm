/*!
 *  \file   Function_Templates_impl.hpp
 *  \brief  Implement all the function implements in the header file Function_Templates.hpp
 *
 */


/*!
 *  \fn     template<typename Comparable> const Comparable& findMax(const std::vector<Comparable>& arr)
 *  \brief  Return the maximum item in the array arr
 *  \param  arr - the vector you input
 *  \return the maximum item of the array, reference to the maximum elemen.
 *  \note   Assume arr.size > 0 \n
 *          Comparable objects must provide operator< and operator=
 */

#include <functional>

template<typename Comparable> const Comparable& findMax(const std::vector<Comparable>& arr)
{
    int maxIndex = 0;
    for (size_t index = 1; index < arr.size(); ++index)
    {
        if (arr[maxIndex] < arr[index])
        {
            maxIndex = index;
        }
    }
    return arr[maxIndex];
}

template<typename ObjectType> const ObjectType& findMaximum(const std::vector<ObjectType>& arr)
{
    return findMax(arr, std::less<ObjectType>{});
}

/*!
 *  \brief  Generic \a findMax, with a function object, Version #1.
 *  \note   Precondition: arr.size() > 0
 */
template<typename ObjectType, typename Comparator>
const ObjectType& findMax(const std::vector<ObjectType>& arr, Comparator cmp)
{
    int maxIndex = 0;
    for (size_t index = 1; index < arr.size(); ++index)
    {
        if (cmp.isLessThan(arr[maxIndex], arr[index]))
        {
            maxIndex = index;
        }
    }
    return arr[maxIndex];
}

template<typename ObjectType, typename Comparator>
const ObjectType& findMaximum(const std::vector<std::string>& arr, Comparator cmp)
{
    int maxIndex = 0;
    for (size_t index = 1; index < arr.size(); ++index)
    {
        if (cmp(arr[maxIndex], arr[index]))
        {
            maxIndex = index;
        }
    }
    return arr[maxIndex];
}
