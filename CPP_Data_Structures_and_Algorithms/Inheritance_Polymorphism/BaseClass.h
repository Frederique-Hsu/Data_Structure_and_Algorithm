/*****************************************************************************************
 * File name		: BaseClass.h
 * Description		: Define the class BaseClass.
 * Creator			: Frederick Hsu
 * Creation date	: Sun. 28 Feb., 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *****************************************************************************************/


#ifndef BASE_CLASS_H
#define BASE_CLASS_H

 	class BaseClass
 	{
 	private:
 		void h(void);
 	public:
 		BaseClass(void);
 		void f(char *s = "unknown");
 	protected:
 		void g(char *s = "unknown");
 	};

#endif	/*  BASE_CLASS_H  */