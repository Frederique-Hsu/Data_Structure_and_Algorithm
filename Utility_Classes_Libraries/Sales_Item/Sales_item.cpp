#include "Sales_item.h"

string make_plural(size_t number, const string& word, const string& ending)
/* copy constructor used to copy the return value;
 * parameters are references, so they aren't copied.
 */
{
    if (number > 1)
        return (word + ending);
    else
    {
        /* here called the "string::string(const string& orig)" copy constructor */
        return word;
    }
}

bool Sales_item::same_isbn(const Sales_item &other) const
{
    return (isbn == other.isbn);
}

double Sales_item::avg_price() const
{
    if (units_sold)
        return (revenue/units_sold);
    else
        return 0;
}

#if 1
Sales_item::Sales_item() : units_sold(0), revenue(0.00)
#else
Sales_item::Sales_item() : isbn(10, '9'), units_sold(0), revenue(0.00)
#endif
{
}

Sales_item::~Sales_item()
{
    cout << "called Sales_item::~Sales_item() destructor." << endl;
}

Sales_item::Sales_item(const string& book) : isbn(book), units_sold(0), revenue(0.0)
{
}

Sales_item::Sales_item(istream& in)
{
    in >> *this;
}

Sales_item::Sales_item(const Sales_item& orig) : isbn(orig.isbn),
                                                 units_sold(orig.units_sold),
                                                 revenue(orig.revenue)
{
}

Sales_item::Sales_item(const string& book, int cnt, double price) :
    isbn(book), units_sold(static_cast<unsigned>(cnt)), revenue(cnt * price)
{
}

istream& operator>>(istream& in, Sales_item& item)
{
    cout << endl << "Please enter the book's ISBN: ";
    in >> item.isbn;
    cout << "enter the amount to sell, units_sold: ";
    in >> item.units_sold;
    cout << "enter the revenue: ";
    in >> item.revenue;
    return in;
}
