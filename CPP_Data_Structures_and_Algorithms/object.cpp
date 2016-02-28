/********************************************************************************
 * File name		: object.cpp
 * Description		: Study the basic concept of Object-Oriented Programming.
 * Creator			: Frederick Hsu
 * Creation date	: Sun.	28 Feb., 2016
 * Copyright(C)		2016	All rights reserved.
 *
 ********************************************************************************/


#include <iostream>
#include <cstring>

using namespace std;


class C
{
private:
	char dataMember1[20];
	int dataMember2;
	double dataMember3;
public:
	C(char *s = "", int i = 0, double d = 1)
	{
		strcpy(dataMember1, s);
		dataMember2 = i;
		dataMember3 = d;
	}

	void memberFunction1(void)
	{
		cout<<dataMember1<<"\n"<<dataMember2<<"\n"<<dataMember3<<endl;
		return;
	}

	void memberFunction2(int i, char *s = "unkown")
	{
		dataMember2 = i;
		cout<<i<<" received from "<<s<<endl;
		return;
	}
protected:
};

class intClass
{
private:
	int storage[50];

};

class floatClass
{
private:
	float storage[50];
};

template<class genType, int size = 50>
class genClass
{
private:
	genType storage[size];
};

template<typename type>
void mySwap(type& e1, type& e2)
{
	type tmp = e1;
	e1 = e2;
	e2 = tmp;
}

/***********************************************************************************************/

int main(int argc, char *argv[])
{
	C object1("object1", 100, 200.50), object2("object2"), object3;
	object1.memberFunction1();
	object1.memberFunction2(123);
	object1.memberFunction2(250, "object1");

	genClass<int, 20> intObject;
	genClass<float> floatClass;

	int m = 5, n = 12;
	mySwap(m, n);
	cout<<"m = "<<m<<", n = "<<n<<endl;

	float x = 0.12, y = 8.15;
	mySwap(x, y);
	cout<<"x = "<<x<<", y = "<<y<<endl;

/*******************************/
	cout<<endl;
	return 0;
}