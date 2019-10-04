/**************************************************************************************************
 * File name    : function_template.cpp
 * Description  : Move the implementation of function templates to this same-name source file,
 *              : in order to separate the prototype with corresponding implementation.
 * Creator      : Frederick Hsu
 * Creation date: Sat.  05  Oct. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/


template<class T, size_t N> void array_init(T (&parm)[N])
{
    for (size_t index = 0; index != N; ++index)
    {
        parm[index] = 0;
    }
}