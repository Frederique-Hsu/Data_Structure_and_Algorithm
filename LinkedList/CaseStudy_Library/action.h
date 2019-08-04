#ifndef ACTION_H
#define ACTION_H

	#include <iostream>
	#include <list>

	#include "Book_Author_Patron.h"

	#define TEMPLATE_OPERATOR_OVERLOAD

	using namespace std;

	void checkOutBook();
	void returnBook();
	void includeBook();
	char* getString(const char* msg);
	void status();

	#if !defined(TEMPLATE_OPERATOR_OVERLOAD)
		template<typename T>
		ostream& operator<<(ostream& out, const list<T>& lst)
		{
			list<T>::const_iterator ref;	/* Why cannot define the const_iterator pointer? when the typename T is generic. */
			for (ref = lst.begin(); ref != lst.end(); ref++)
			{
				out << *ref;	/* Overloaded << */
			}
			return out;
		}
	#else
		ostream& operator<<(ostream& out, const list<Author>& lst);

		ostream& operator<<(ostream& out, const list<Patron>& lst);
	#endif

		int menu();

#endif	/* ACTION_H */