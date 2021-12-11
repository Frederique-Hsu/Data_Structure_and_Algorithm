/*!
 *  \file   Functions.hpp
 *  \brief  Study the parameter-passing and return-passing topics about functions.
 *  \author Frederique Hsu
 *  \date   Sat.    11 Dec. 2021
 * 
 */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

    /* Includes */
    #include <vector>
    #include <string>

    /* Prototypes */
    int randomInt(int from, int to);

    template<typename LargeType> LargeType randomItem(const std::vector<LargeType>& arr);
    template<typename LargeType> const LargeType& randomItem2(const std::vector<LargeType>& arr);

    std::vector<int> partialSum(const std::vector<int>& arr);

    /* Implementations */
    template<typename LargeType> LargeType randomItem(const std::vector<LargeType>& arr)
    {
        return arr[randomInt(0, arr.size() -1)];
    }

    template<typename LargeType> const LargeType& randomItem2(const std::vector<LargeType>& arr)
    {
        return arr[randomInt(0, arr.size() - 1)];
    } 


#endif  /* FUNCTIONS_HPP */
