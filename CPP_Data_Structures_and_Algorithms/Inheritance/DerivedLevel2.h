/*****************************************************************************************
 * File name		: DerivedLevel2.h
 * Description		: Define the class DerivedLevel2.
 * Creator			: Frederick Hsu
 * Creation date	: Sun. 28 Feb., 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *****************************************************************************************/

#ifndef DERIVEDLEVEL2_H
#define DERIVEDLEVEL2_H

 	#include "Derived1Level1.h"
 	#include "Derived2Level1.h"

 
 	class DerivedLevel2 : public Derived1Level1, public Derived2Level1
 	{
 	private:
 	public:
 		void f(char *s = "unknown");
 	protected:
 	};

#endif	/*  DERIVEDLEVEL2_H  */