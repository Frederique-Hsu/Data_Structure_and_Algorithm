/*****************************************************************************************
 * File name		: test.cpp
 * Description		: Design the test cases to perform the testing for current project.
 * Creator			: Frederick Hsu
 * Creation date	: Sun. 28 Feb., 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *****************************************************************************************/


#include "test.h"
#include "BaseClass.h"
#include "Derived1Level1.h"
#include "Derived2Level1.h"
#include "DerivedLevel2.h"
#include "Polymorphism.h"

void performTestCases(void)
{
    performInheritanceTestCases();
    performPolymorphismTestCases();
}

void performInheritanceTestCases(void)
{
	BaseClass bc;
	Derived1Level1 d1l1;
	Derived2Level1 d2l1;
	DerivedLevel2 dl2;

	bc.f("main(1)");
	// bc.g();		// error : BaseClass::g() is not accessiblels
	// bc.h();		// error : BaseClass::h() is not accessible
	
	d1l1.f("main(2)");
	// d1l1.g();	// error : BaseClass::g() is not accessible
	d1l1.h("main(3)");
	
	d2l1.f("main(4)");
	// d2l1.g();
	// d2l1.h();

	dl2.f("main(5)");
	// dl2.g();
	dl2.h();

	return;
}


void performPolymorphismTestCases(void)
{
    Class1 object1, *p;
    Class2 object2;
    Class3 object3;
    
    p = &object1;
    p->f();
    p->g();
    
    p = (Class1 *)&object2;
    p->f();
    p->g();
    
    p = (Class1 *)&object3;
    p->f();  // Possibly abnormal program termination
    p->g();
    // p->h();  // h() is not a member of Class1
    
    return;
}