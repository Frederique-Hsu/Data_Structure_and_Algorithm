/*************************************************************************************************
 * File name	: student.cpp
 * Description	: Implement the class Student
 * Creator		: Fredericks Hsu
 * Creation date: Tue.	29 March, 2016
 * Copyright(C)	2016	All rights reserved.
 *
 *************************************************************************************************/

#include "student.h"

Student::Student(void) : majorLen(10)
{
	Personal();
	major = new char[majorLen];
}

Student::Student(char *ssn,
				 char *n,
				 char *c,
				 int  y,
				 long s,
				 char *m) : majorLen(11)
{
	Personal(ssn, n, c, y, s);
	major = new char[majorLen + 1];
	strcpy(major, m);
}

void Student::writeToFile(fstream& out) const
{
	Personal::writeToFile(out);
	out.write(major, majorLen);
	return;
}

void Student::readFromFile(fstream& in)
{
	Personal::readFromFile(in);
	in.read(major, majorLen);
}

int Student::size(void) const
{
	return (Personal::size() + majorLen);
}

ostream& Student::writeLegibly(ostream& out)
{
	Personal::writeLegibly(out);
	major[majorLen] = '\0';
	out << ", major = " << major;
	return out;
}

istream& Student::readFromConsole(istream& in)
{
	Personal::readFromConsole(in);
	char s[80] = {0};
	cout << "Major : ";
	in.getline(s, 80);
	strncpy(major, s, majorLen);
	return in;
}

ostream& operator<<(ostream& out, Student& sr)
{
	return (sr.writeLegibly(out));
}

istream& operator>>(istream& in, Student& sr)
{
	return (sr.readFromConsole(in));
}