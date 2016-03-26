/*******************************************************************************
 * File name : vector_function_handling.h
 * Description : Demonstrate the vector function handling.
 * Creator : Frederick Hsu
 * Creation date : Sun. 20 March, 2016
 * Copyright(C) 2016 All rights reserved.
 * 
 *******************************************************************************/

#include "vector_function_handling.h"
#include "Person.h"

bool fcnt(int n)
{
    return (n<4);
}

void performTesting4VectorFcnt(void)
{
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v1;
    printVector("v1", v1);
    
    for (int j = 1; j<=5; j++)
    {
        v1.push_back(j);
    }
    printVector("v1", v1);
    
    vector<int> v2(3, 7);
    vector<int>::iterator i1 = v1.begin() + 1;
    vector<int> v3(i1, i1+2);
    vector<int> v4(v1);
    vector<int> v5(5);
    
    v5[1] = v5.at(3) = 9;
    v3.reserve(6);
    v4.resize(7);
    v4.resize(3);
    v4.clear();
    
    v4.insert(v4.end(), v3[1]);
    v4.insert(v4.end(), v3.at(1));
    v4.insert(v4.end(), 2, 4);
    v4.insert(v4.end(), v1.begin()+1, v1.end()-1);
    printVector("v4", v4);
    
    v4.erase(v4.end()-2);
    v4.erase(v4.begin(), v4.begin()+4);
    printVector("v4", v4);
    
    v4.assign(3, 8);
    v4.assign(a, a+3);
    
    vector<int>::reverse_iterator i3 = v4.rbegin();
    for (; i3 != v4.rend(); i3++)
    {
        cout<<*i3<<", ";
    }
    cout<<endl;
    
    /* Algorithms */
    v5[0] = 3;
    replace_if(v5.begin(), v5.end(), fcnt, 7);
    
    v5[0] = 3;
    v5[2] = v5[4] = 0;
    replace(v5.begin(), v5.end(), 0, 7);
    printVector("v5", v5);
    
    sort(v5.begin(), v5.end());
    printVector("v5", v5);
    
    sort(v5.begin(), v5.end(), greater<int>());
    printVector("v5", v5);
    
    v5.front() = 2;
    printVector("v5", v5);

    vector<Person> v6(1, Person("Gregg", 25));
    v6.push_back(Person("Ann", 30));
    v6.push_back(Person("Bill", 20));

    sort(v6.begin(), v6.end());
    sort(v6.begin(), v6.end(), greater<Person>());
    sort(v6.begin(), v6.end(), lesserAge);
    
    return;
}