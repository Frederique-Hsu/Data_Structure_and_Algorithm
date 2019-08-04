#include "Book_Author_Patron.h"

ostream& Book::printBook(ostream& out) const
{
	out << " * " << title;
	if (patron != 0)
	{
		out << " - checked out to " << patron->name;
	}
	out << endl;
	return out;
}

ostream& Author::printAuthor(ostream& out) const
{
	out << name << endl;
	list<Book>::const_iterator ref = books.begin();
	for (; ref != books.end(); ref++)
	{
		out << *ref;
	}
	return out;
}

ostream& Patron::printPatron(ostream& out) const
{
	out << name;
	if (!books.empty())
	{
		out << " has the following books:\n";
		list<CheckedOutBook>::const_iterator bk = books.begin();
		for (; bk != books.end(); bk++)
		{
			out << " * " << bk->author->name << ", " << bk->book->title << endl;
		}
	}
	else
	{
		out << " has no books\n";
	}
	return out;
}