/*****************************************************************************************
 * File name		: Derived2Level1.h
 * Description		: Define the class Derived2Level1.
 * Creator			: Frederick Hsu
 * Creation date	: Sun. 28 Feb., 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *****************************************************************************************/

#ifndef DERIVED2LEVEL1_H
#define DERIVED2LEVEL1_H

 	#include "BaseClass.h"

 	class Derived2Level1 : public virtual BaseClass
 	{
 	private:
 	public:
 		void f(char *s = "unknown");
 	protected:
 	};

#endif	/*  DERIVED2LEVEL1_H  */