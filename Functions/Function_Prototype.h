#ifndef FUNCTION_PROTOTYPE_H
#define FUNCTION_PROTOTYPE_H

    #include <string>
    #include <vector>
    using namespace std;

    #define REFERENCE_PARAMETERS

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
    void ptrswap(int *&v1, int *&v2);

    vector<int>::const_iterator find_val(vector<int>::const_iterator beg,
                                         vector<int>::const_iterator end,
                                         int value,
                                         vector<int>::size_type& occurs);
    bool isShorter(const string& s1, const string& s2);
    int incr(int &val);
    string::size_type find_char(const string& s, char c);
    bool is_sentence(const string& s);
    void print(vector<int>::const_iterator beg, vector<int>::const_iterator end);

    /* array as the parameter to function
     * three equivalent definitions of printValues
     */
    void printValues(int*);
    void printValues(int[]);
    void printValues(int[10]);
    void printValues(const int iarr[], size_t size);
    void printValues(int (&arr)[10]);
    void printValues(int (*matrix)[10], int rowSize);   /* first parameter is an array, whose elements are arrays of 10 ints */
    void printValues(int matrix[][10], int rowSize);

    string make_plural(size_t ctr, const string& word, const string& ending);
    const string& shorterString(const string& s1, const string& s2);
    char& get_val(string& str, string::size_type pos);

#endif  /* FUNCTION_PROTOTYPE_H */
