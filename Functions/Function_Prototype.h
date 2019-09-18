#ifndef FUNCTION_PROTOTYPE_H
#define FUNCTION_PROTOTYPE_H

    #include <string>
    using namespace std;

    // #define REFERENCE_PARAMETERS

    int gcd(int v1, int v2);
    bool is_present(int*, int);
    int count(const string&, char);
    // Date &calendar(const char*);    /* returns reference to Date */
    void process();     /* implicit void parameter list */
    int* foo_bar();     /* function pointer */
    int manip(int v1, int v2);
    void reset(int *ip);
    void use_ptr(const int *p);

    void fcn(const int i);      /* fcn can read but not write to i */
    // void fcn(int i);        /* error: redefines fcn(int) */

#if !defined (REFERENCE_PARAMETERS)
    /* incorrect version of swap: The arguments are not changed */
    void swap(int v1, int v2);
#else
    void swap(int& v1, int& v2);
#endif

#endif  /* FUNCTION_PROTOTYPE_H */
