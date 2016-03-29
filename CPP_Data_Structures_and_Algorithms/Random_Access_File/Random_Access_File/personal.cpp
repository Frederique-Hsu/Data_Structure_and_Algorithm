/*************************************************************************************************
 * File name	: personal.cpp
 * Description	: Implement the class Personal
 * Creator		: Fredericks Hsu
 * Creation date: Tue.	29 March, 2016
 * Copyright(C)	2016	All rights reserved.
 *
 *************************************************************************************************/


#include "personal.h"

Personal::Personal(void) : nameLen(10), cityLen(10)
{
	name = new char[nameLen+1];
	city = new char[cityLen+1];
}

Personal::Personal(char *ssn, char *n, char *c, int y, long s) : nameLen(10), cityLen(10)
{
	name = new char[nameLen+1];
	city = new char[cityLen+1];
	strcpy(SSN, ssn);
	strcpy(city, c);
	strcpy(name, n);
	year = y;
	salary = s;
}

Personal::~Personal(void)
{
	// Empty
}

void Personal::writeToFile(fstream& out) const
{
	out.write(SSN, 9);
	out.write(name, nameLen);
	out.write(city, cityLen);
	out.write(reinterpret_cast<const char*>(&year), sizeof(int));
	out.write(reinterpret_cast<const char*>(&salary), sizeof(long));
	return;
}

void Personal::readFromFile(fstream& in)
{
	in.read(SSN, 9);
	in.read(name, nameLen);
	in.read(city, cityLen);
	in.read(reinterpret_cast<char*>(&year), sizeof(int));
	in.read(reinterpret_cast<char*>(&salary), sizeof(long));
	return;
}

void Personal::readKey(void)
{
	char s[80] = {0};
	cout << "Enter the SSN: ";
	cin.getline(s, 80); strncpy(SSN, s, 9);
	return;
}

int Personal::size(void) const
{
	return (9+nameLen+cityLen+sizeof(year)+sizeof(salary));
}

bool Personal::operator==(const Personal& pr) const
{
	return (0 == strncmp(pr.SSN, SSN, 9));
}

ostream& Personal::writeLegibly(ostream& out)
{
	SSN[9] = '\0';
	name[nameLen] = '\0';
	city[cityLen] = '\0';
	out << "SSN = " << SSN
		<< ", name = " << name
		<< ", city = " << city
		<< ", year = " << year
		<< ", salary = " << salary;
	return out;
}

ostream& operator<<(ostream& out, Personal& pr)
{
	return pr.writeLegibly(out);
}

istream& operator>>(istream& in, Personal& pr)
{
	return pr.readFromConsole(in);
}

istream& Personal::readFromConsole(istream& in)
{
	SSN[9] = '\0';
	name[nameLen] = '\0';
	city[cityLen] = '\0';
	char s[80] = {0};

	cout << "SSN : ";
	in.getline(s, 80);
	strncpy(SSN, s, 9);

	cout << "Name : ";
	in.getline(s, 80);
	strncpy(name, s, nameLen);

	cout << "City : ";
	in.getline(s, 80);
	strncpy(city, s, cityLen);

	cout << "Birthyear : ";
	in >> year;

	cout << "Salary : ";
	in >> salary;

	in.ignore();

	return in;
}