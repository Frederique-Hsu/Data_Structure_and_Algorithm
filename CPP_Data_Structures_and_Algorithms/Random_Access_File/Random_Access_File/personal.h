/*************************************************************************************************
 * File name	: personal.h
 * Description	: Define the class Personal
 * Creator		: Fredericks Hsu
 * Creation date: Tue.	29 March, 2016
 * Copyright(C)	2016	All rights reserved.
 *
 *************************************************************************************************/

#ifndef PERSONAL_H
#define PERSONAL_H

	#include <fstream>
	#include <cstring>
	#include <iostream>

	using namespace std;

	class Personal
	{
	private:
	public:
		Personal(void);
		Personal(char*, char*, char*, int, long);
		~Personal(void);

		void writeToFile(fstream&) const;
		void readFromFile(fstream&);
		void readKey(void);
		int size(void) const;
		bool operator==(const Personal& pr) const;
	protected:
		const int nameLen;
		const int cityLen;
		char SSN[10];
		char *name;
		char *city;
		int year;
		long salary;

		ostream& writeLegibly(ostream&);
		friend ostream& operator<<(ostream& out, Personal& pr);
		istream& readFromConsole(istream&);
		friend istream& operator>>(istream& in, Personal& pr);
	};

#endif	/* PERSONAL_H */