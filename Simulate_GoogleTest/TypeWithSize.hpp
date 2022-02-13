/*!
 *  \file   TypeWithSize.hpp
 *  \brief  
 * 
 */

#pragma once

namespace internal
{
    template<size_t size> class TypeWithSize
    {
    public:
        typedef void UInt;
    };

    template<> class TypeWithSize<4>
    {
    public:
        typedef int Int;
        typedef unsigned int UInt;
    };

    template<> class TypeWithSize<8>
    {
    public:
        typedef long long Int;
        typedef unsigned long long UInt;
    };

    typedef TypeWithSize<4>::Int    Int32;
    typedef TypeWithSize<4>::UInt   UInt32;
    typedef TypeWithSize<8>::Int    Int64;
    typedef TypeWithSize<8>::UInt   UInt64;
    typedef TypeWithSize<8>::Int    TimeInMillis;
}