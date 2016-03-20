/*****************************************************************************************
 * File name		: Derived1Level1.h
 * Description		: Define the class Derived1Level1.
 * Creator			: Frederick Hsu
 * Creation date	: Sun. 28 Feb., 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *****************************************************************************************/


#ifndef DERIVED1LEVLE1_H
#define DERIVED1LEVLE1_H

 	#include "BaseClass.h"

 	class Derived1Level1 : public virtual BaseClass
 	{
 	private:
 	public:
 		void f(char *s = "unknown");
 		void h(char *s = "unknown");
 	protected:
 	};

#endif	/*  DERIVED1LEVLE1_H  */