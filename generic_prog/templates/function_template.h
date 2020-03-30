#ifndef FUNCTION_TEMPLATE_H
#define FUNCTION_TEMPLATE_H

    #include <string>
    #include <cstddef>
    #include <vector>

    using namespace std;

    template<typename Type> int compare(const Type&, const Type&);

    // int *pfnct(const int&, const int&) = compare;

    /* overloaded versions of func; each takes a different function pointer type */
    void func(int(*) (const string&, const string&));
    void func(int(*) (const int&, const int&));
    // func(compare<int>);     /* OK: explicitly specify which version of compare */

    template<typename T, size_t N> void array_init(T (&parm)[N]);
    template<size_t N> void fibonacci_series(unsigned (&fib)[N]);
    template<size_t N> void fibonacci_series(vector<size_t> &fib);
    template<size_t N> void fibonacci_ratio_series(vector<long double> &fib_ratio);

/**************************************************************************************************/

    #include "function_template.cpp"

#endif  /* FUNCTION_TEMPLATE_H */