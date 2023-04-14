/*!
 *  \file   SuiteApiREsolver.hpp
 *  \brief  
 * 
 */

#pragma once

#include <type_traits>

#include "Test.hpp"

namespace testing
{
    namespace internal
    {
        using SetUpTearDownSuiteFuncType = void (*)();

        template<typename T> struct SuiteApiResolver : T
        {
            using Test = typename std::conditional<sizeof(T) != 0, ::testing::Test, void>::type;

            static SetUpTearDownSuiteFuncType GetSetUpCaseOrSuite(const char* filename, int line_num);
            static SetUpTearDownSuiteFuncType GetTearDownCaseOrSUite(const char* filename, int line_num);
        }
    }
}