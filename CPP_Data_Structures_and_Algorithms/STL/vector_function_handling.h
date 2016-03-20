/*******************************************************************************
 * File name : vector_function_handling.h
 * Description : Demonstrate how to handle the function in the vector class template.
 * Creator : Frederick Hsu
 * Creation date : Sun. 20 March, 2016
 * Copyright(C) All rights reserved.
 * 
 *******************************************************************************/


#ifndef VECTOR_FUNCTION_HANDLING_H
#define VECTOR_FUNCTION_HANDLING_H

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <functional>
    
    using namespace std;
    
    template<class T>
    void printVector(char *s, const vector<T>& v)
    {
        cout<<s<<" = (";
        if (v.size() == 0)
        {
            cout<<")\n";
            return;
        }
        
        typename vector<T>::const_iterator i = v.begin();
        for (; i != v.end()-1; i++)
        {
            cout<<*i<<", ";
        }
        cout<<*i<<")\n";
    }
    
    bool fcnt(int n);
    
    void performTesting4VectorFcnt(void);

#endif  /* VECTOR_FUNCTION_HANDLING_H */