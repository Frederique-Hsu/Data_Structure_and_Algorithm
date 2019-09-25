#include "Item_base.h"

Item_base::Item_base(const string& book, double sales_price) : isbn(book), price(sales_price)
{
}

string Item_base::book() const
{
    return isbn;
}

double Item_base::net_price(size_t n) const
/* returns total sales price for a specified number of items,
 * derived classes will override and apply different discount algorithms.
 */
{
    return (n * price);
}

Item_base::~Item_base()
{
}

void print_total(ostream& os, const Item_base& item, size_t n)
/* calculate and print price for given number of copies, applying any discounts */
{
    os << "ISBN: " << item.book() << "\tnumber sold: " << n
       << "\ttotal price: "
          /* virtual call: which version of net_price to call is resolved at run time. */
       << item.net_price(n)
       << endl;
}
