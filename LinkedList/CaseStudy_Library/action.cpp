#include "action.h"

#include <ctype.h>


list<Author> catalog['Z' + 1];

list<Patron> people['Z' + 1];

void checkOutBook()
{
	Patron patron;
	Author author;
	Book book;
	list<Author>::iterator authorRef;
	list<Book>::iterator bookRef;
	patron.name = getString("Enter patron's name: ");
	while (true)
	{
		author.name = getString("Enter author's name: ");
		authorRef = find(catalog[author.name[0]].begin(), catalog[author.name[0]].end(), author);
		if (authorRef == catalog[author.name[0]].end())
		{
			cout << "Misspelled author's name\n";
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		book.title = getString("Enter the title of the book: ");
		bookRef = find((*authorRef).books.begin(), (*authorRef).books.end(), book);
		if (bookRef == (*authorRef).books.end())
		{
			cout << "Misspelled title\n";
		}
		else
		{
			break;
		}
	}

	list<Patron>::iterator patronRef = find(people[patron.name[0]].begin(), people[patron.name[0]].end(), patron);
	CheckedOutBook outBook(authorRef, bookRef);
	
	if (patronRef == people[patron.name[0]].end())
	{
		patron.books.push_front(outBook);		/* a new patron in the history */
		people[patron.name[0]].push_front(patron);
		(*bookRef).patron = &(*people[patron.name[0]].begin());
	}
	else
	{
		(*patronRef).books.push_front(outBook);
		(*bookRef).patron = &(*patronRef);
	}
}

void returnBook()
{
	Patron patron;
	Book book;
	Author author;
	list<Patron>::iterator patronRef;
	list<Book>::iterator bookRef;
	list<Author>::iterator authorRef;

	while (true)
	{
		patron.name = getString("Enter patron's name: ");
		patronRef = find(people[patron.name[0]].begin(), people[patron.name[0]].end(), patron);
		if (patronRef == people[patron.name[0]].end())
		{
			cout << "Patron's name misspelled\n";
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		author.name = getString("Enter author's name: ");
		authorRef = find(catalog[author.name[0]].begin(), catalog[author.name[0]].end(), author);
		if (authorRef == catalog[author.name[0]].end())
		{
			cout << "Misspelled author's name\n";
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		book.title = getString("Enter the title of the book: ");
		bookRef = find((*authorRef).books.begin(), (*authorRef).books.end(), book);
		if (bookRef == (*authorRef).books.end())
		{
			cout << "Misspelled title\n";
		}
		else
		{
			break;
		}
	}
	CheckedOutBook outBook(authorRef, bookRef);
	(*bookRef).patron = 0;
	(*patronRef).books.remove(outBook);
}

void includeBook()
{
	Author newAuthor;
	Book newBook;
	newAuthor.name = getString("Enter author's name: ");
	newBook.title = getString("Enter the title of the book: ");
	list<Author>::iterator oldAuthor = find(catalog[newAuthor.name[0]].begin(), 
		                                    catalog[newAuthor.name[0]].end(), 
		                                    newAuthor);
	if (oldAuthor == catalog[newAuthor.name[0]].end())
	{
		newAuthor.books.push_front(newBook);
		catalog[newAuthor.name[0]].push_front(newAuthor);
	}
	else
	{
		(*oldAuthor).books.push_front(newBook);
	}
}

char* getString(const char* msg)
{
	char s[82], i, *destin;
	cout << msg;
	cin.get(s, 80);
	while (cin.get(s[81]) && (s[81] != '\n'));		/* Discard overflowing characters */

	destin = new char[strlen(s) + 1];
	for (i = 0; destin[i] == toupper(s[i]); i++)
	{
	}
	return destin;
}

void status()
{
	register int i;
	cout << "Library has the following books:\n\n";
	for (i = 'A'; i < 'Z'; ++i)
	{
		if (!catalog[i].empty())
		{
			cout << catalog[i];
		}
	}
	cout << "\nThe following people are using the library:\n\n";
	for (i = 'A'; i <= 'Z'; ++i)
	{
		if (!people[i].empty())
		{
			cout << people[i];
		}
	}
}

int menu()
{
	int option;
	std::cout << "\nEnter one of the following options:\n"
		<< "1. Include a book in the catalog\n"
		<< "2. Check out a book\n"
		<< "3. Return a book\n"
		<< "4. Status\n"
		<< "5. Exit\n"
		<< "Your options? ";
	std::cin >> option;
	std::cin.get();		/* discard '\n' */
	return option;
}

#if !defined(TEMPLATE_OPERATOR_OVERLOAD)
#else
	ostream& operator<<(ostream& out, const list<Author>& lst)
	{
		for (list<Author>::const_iterator ref = lst.begin(); ref != lst.end(); ref++)
		{
			out << *ref;
		}
		return out;
	}

	ostream& operator<<(ostream& out, const list<Patron>& lst)
	{
		for (list<Patron>::const_iterator ref = lst.begin(); ref != lst.end(); ref++)
		{
			out << *ref;
		}
		return out;
	}
#endif