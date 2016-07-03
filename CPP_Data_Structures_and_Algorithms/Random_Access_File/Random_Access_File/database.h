/*************************************************************************************************
 * File name	: database.h
 * Description	: Define the class template Database
 * Creator		: Fredericks Hsu
 * Creation date: Tue.	29 March, 2016
 * Copyright(C)	2016	All rights reserved.
 *
 *************************************************************************************************/

#ifndef DATABASE_H
#define DATABASE_H

	#include <fstream>
	using namespace std;

	template<class T>
	class Database
	{
	private:
	public:
		Database(void);
		void run(void);
	protected:
		fstream database;
		char fName[20];
		ostream& print(ostream&);
		void add(T&);
		bool find(T&);
		void modify(const T&);

		friend ostream& operator<<(ostream& out, Database& db);
	};

#endif	/* DATABASE_H */