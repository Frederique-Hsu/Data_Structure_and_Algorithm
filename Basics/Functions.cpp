/*!
 *  \file   Functions.cpp
 *  \brief  Implements those user-defined functions.
 *  \author Frederique Hsu
 *  \date   Sat.    11 Dec. 2021
 */

#include "Functions.hpp"

#include <math.h>
#include <time.h>
#include <assert.h>

int randomInt(int from, int to)
{
    assert(to >= from);
    srandom(time(NULL));

    int randnum = (rand() % to);
    if (randnum >= from)
        return randnum;
    else // if (randnum < from)
        return (randnum + (to - from));
}

std::vector<int> partialSum(const std::vector<int>& arr)
{
    std::vector<int> result(arr.size());

    result[0] = arr[0];
    for (size_t index = 1; index < arr.size(); ++index)
    {
        result[index] = result[index-1] + result[index];
    }
    return result;      /* Returning of a stack-allocated rvalue in C++11 */
}

namespace My
{

}
