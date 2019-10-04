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

    template<typename T> inline T min(const T& v1, const T& v2)
    {
        if (v1 <= v2)
            return v1;
        else
            return v2;
    }

    template<class Type> Type calc(const Type& a, const Type& b);
    template<class T, size_t N> void array_init(T (&parm)[N]);


    #include "function_template.cpp"

#endif  /* FUNCTION_TEMPLATE_H */
