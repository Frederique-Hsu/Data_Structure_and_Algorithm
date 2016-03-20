/*********************************************************************
 * File name		: RefClass.h
 * Description		: 引用類可直接訪問私有成員變量
 * Creator			: Frederick Hsu
 * Creation date	: Thu.	03 March, 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *********************************************************************/

#ifndef REFCLASS_H
#define REFCLASS_H

 	class RefClass
 	{
 	private:
 		int n;
 	public:
 		RefClass(void);
 		int& getRefN(void);
 		int getN(void);
 	};

#endif	/*  REFCLASS_H  */