/**************************************************************************************************
 * File name    : function_template.h
 * Description  : Declare the prototype of some function templates here.
 * Creator      : Frederick Hsu
 * Creation date: Sat.  05  Oct. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#ifndef FUNCTION_TEMPLATE_H
#define FUNCTION_TEMPLATE_H

    #include <cstddef>
    #include <vector>
    using namespace std;

    template<typename T> int compare(const T& v1, const T& v2)
    {
        if (v1 < v2)
        {
            return -1;
        }
        if (v2 < v1)
        {
            return 1;
        }
        return 0;
    }

    int (*pcomp)(const int&, const int&) = compare;

    void fnct(int(*) (const int&, const int&));

    template<typename T> inline T min(const T& v1, const T& v2)
    {
        if (v1 <= v2)
            return v1;
        else
            return v2;
    }

    template<class Type> Type calc(const Type& a, const Type& b);
    template<class T, size_t N> void array_init(T (&parm)[N]);
    template<class T1, class T2, class T3> T1 sum(T2 a, T3 b);
    template<class T1, class T2, class T3> T3 alternative_sum(T2 a, T1 b);

    template<size_t N> void generate_fibonacci(unsigned (&fib)[N]);
    template<size_t N> void generate_fibonacci(vector<size_t>& fib);


    #include "function_template.cpp"    /* inclusion compilation model */

#endif  /* FUNCTION_TEMPLATE_H */
