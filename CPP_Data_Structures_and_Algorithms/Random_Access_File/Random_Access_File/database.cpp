/*************************************************************************************************
 * File name	: database.cpp
 * Description	: Implement the class template Database
 * Creator		: Fredericks Hsu
 * Creation date: Tue.	29 March, 2016
 * Copyright(C)	2016	All rights reserved.
 *
 *************************************************************************************************/

#include "database.h"
#include "personal.h"
#include "student.h"
#include <iostream>

template<class T>
Database<T>::Database(void)
{
	// Empty
}

template<class T>
void Database<T>::add(T& d)
{
	database.open(fName, ios::in|ios::out|ios::binary);
	database.seekp(0, ios::end);
	d.writeToFile(database);
	database.close();
}

template<class T>
bool Database<T>::find(T& d)
{
	T tmp;
	database.open(fName, ios::in|ios::binary);
	while (!database.eof())
	{
		tmp.readFromFile(database);
		if (tmp == d)
		{
			database.close();
			return true;
		}
	}
	database.close();
	return false;
}

template<class T>
void Database<T>::modify(const T& d)
{
	T tmp;
	database.open(fName, ios::in|ios::out|ios::binary);

	while (!database.eof())
	{
		tmp.readFromFile(database);
		if (tmp == d)
		{
			cin >> tmp;
			database.seekp(-d.size(), ios::cur);
			tmp.writeToFile(database);
			return;
		}
	}
	database.close();
	cout << "The record to be modified is not in the database." << endl;
	return;
}

template<class T>
ostream& Database<T>::print(ostream& out)
{
	T tmp;
	database.open(fName, ios::in|ios::binary);
	
	while (true)
	{
		tmp.readFromFile(database);
		if (database.eof())
		{
			break;
		}
		out << tmp << endl;
	}
	database.close();
	return out;
}

template<class T>
void Database<T>::run(void)
{
	cout << "File name : ";
	cin >> fName;

	char option[5] = {0};
	T rec;
	cout << "1. Add, 2. Find, 3. Modify a record; 4. Exit" << endl;
	cout << "Enter an option : ";
	cin.getline(option, 4);

	while (cin.getline(option, 4))
	{
		if (*option == '1')
		{
			cin >> rec;
			add(rec);
		}
		else if (*option == '2')
		{
			rec.readKey();
			cout << "The record is : ";
			if (find(rec) == false)
				cout << "not ";
			cout << "in the database." << endl;
		}
		else if (*option == '3')
		{
			rec.readKey();
			modify(rec);
		}
		else if (*option == '4')
		{
			cout << "Wrong option." << endl;
		}
		else
		{
			return;
		}

		cout << *this;
		cout << "Enter an option : ";
	}
}

template<class T>
ostream& operator<<(ostream& out, Database<T>& db)
{
	return (db.print(out));
}