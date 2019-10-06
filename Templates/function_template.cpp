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

template<class T1, class T2, class T3> T1 sum(T2 a, T3 b)
{
    return (a + b);
}

template<class T1, class T2, class T3> T3 alternative_sum(T2 a, T1 b)
/* poor design: Users must explicitly specify all 3 template parameters */
{
    return (a + b);
}

template<size_t N> void generate_fibonacci(unsigned (&fib)[N])
{
    fib[0] = 1;
    fib[1] = 1;

    for (int index = 2; index < N; ++index)
    {
        fib[index] = fib[index-1] + fib[index-2];
    }
}

template<size_t N> void generate_fibonacci(vector<size_t>& fib)
{
    fib.push_back(1);
    fib.push_back(1);

    for (int index = 2; index < N; ++index)
    {
        fib.push_back(fib[index-1] + fib[index-2]);
    }
}
