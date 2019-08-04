#ifndef BOOK_AUTHOR_PATRON_H
#define BOOK_AUTHOR_PATRON_H

	#include <iostream>
	#include <list>
	#include <string>

	using namespace std;

	class Patron;

	class Book
	{
	public:
		Book()
		{
			title = new char[0xFF];
		}
		~Book()
		{
			delete title;
		}
		bool operator==(const Book& bk) const
		{
			return (strcmp(title, bk.title) == 0);
		}
	private:
		char *title;
		Patron *patron;
		ostream& printBook(ostream&) const;
		friend ostream& operator<<(ostream& out, const Book& bk)
		{
			return bk.printBook(out);
		}

		friend class CheckedOutBook;
		friend Patron;
		friend void includeBook();
		friend void checkOutBook();
		friend void returnBook();
	};

	/*************************************************************************************************/

	class Author
	{
	public:
		Author()
		{
			name = new char[0xFF];
		}
		~Author()
		{
			delete name;
		}
		bool operator==(const Author& ar) const
		{
			return (strcmp(name, ar.name) == 0);
		}
	private:
		char* name;
		list<Book> books;
		ostream& printAuthor(ostream&) const;
		friend ostream& operator<<(ostream& out, const Author& ar)
		{
			return ar.printAuthor(out);
		}
		friend void includeBook();
		friend void checkOutBook();
		friend void returnBook();
		friend class CheckedOutBook;
		friend Patron;
	};

	/*************************************************************************************************/

	class CheckedOutBook
	{
	public:
		CheckedOutBook(list<Author>::iterator ar, list<Book>::iterator bk)
		{
			author = ar;
			book = bk;
		}
		bool operator==(const CheckedOutBook& bk) const
		{
			return ((strcmp(author->name, bk.author->name) == 0) && (strcmp(book->title, bk.book->title) == 0));
		}
	private:
		list<Author>::iterator author;
		list<Book>::iterator book;

		friend void checkOutBook();
		friend void returnBook();
		friend Patron;
	};

	/*************************************************************************************************/

	class Patron
	{
	public:
		Patron()
		{
			name = new char[0xFF];
		}
		~Patron()
		{
			delete name;
		}
		bool operator==(const Patron& pn) const
		{
			return (strcmp(name, pn.name) == 0);
		}
	private:
		char* name;
		list<CheckedOutBook> books;
		ostream& printPatron(ostream&) const;
		friend ostream& operator<<(ostream& out, const Patron& pn)
		{
			return pn.printPatron(out);
		}
		friend void checkOutBook();
		friend void returnBook();
		friend Book;
	};


#endif	/* BOOK_AUTHOR_PATRON_H */