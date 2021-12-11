/*!
 *  \file   Swap.hpp
 *  \brief
 */

#ifndef SWAP_HPP
#define SWAP_HPP

#include <vector>
#include <string>


namespace My
{
    template<typename T> void swap(T& a, T& b);
    /* explicit specialization for T = unsigned */
    template<>           void swap<char>(char& a, char& b);
    template<>           void swap<int>(int& a, int& b);
    template<>           void swap<short>(short& a, short& b);
    template<>           void swap<long>(long& a, long& b);
    template<>           void swap<long long>(long long& a, long long& b);
    template<>           void swap<unsigned>(unsigned& a, unsigned& b);
                         void swap(std::vector<std::string>& x, std::vector<std::string>& y);

    template<typename T> void swap(T& a, T& b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    template<> void swap<int>(int& a, int& b)
    {   /* this method is also appropriate for both signed and unsigned types */
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    template<> void swap<char>(char& a, char& b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    template<> void swap<short>(short& a, short& b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    template<> void swap<long>(long& a, long& b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    template<> void swap<long long>(long long& a, long long& b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    template<> void swap<unsigned>(unsigned& a, unsigned& b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

#if 0
    template<> void swap(double& a, double& b)
    {
        a = a ^ b;      /* float point values DO NOT support binary bit-calculation operator */
        b = a ^ b;
        a = a ^ b;
    }
#endif
}

#include "Swap_impl.hpp"


#endif  /* SWAP_HPP */
