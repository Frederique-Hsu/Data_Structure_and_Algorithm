/*************************************************************************************************
 * File name	: student.h
 * Description	: Define the class Student
 * Creator		: Fredericks Hsu
 * Creation date: Tue.	29 March, 2016
 * Copyright(C)	2016	All rights reserved.
 *
 *************************************************************************************************/


#ifndef STUDENT_H
#define STUDENT_H

	#include "personal.h"

	class Student : public Personal
	{
	private:
	public:
		Student(void);
		Student(char*, char*, char*, int, long, char*);
		
		void writeToFile(fstream&) const;
		void readFromFile(fstream&);
		int size(void) const;
	protected:
		char *major;
		const int majorLen;
		ostream& writeLegibly(ostream&);
		friend ostream& operator<<(ostream& out, Student& sr);
		istream& readFromConsole(istream&);
		friend istream& operator>>(istream& in, Student& sr);
	};

#endif	/* STUDENT_H */