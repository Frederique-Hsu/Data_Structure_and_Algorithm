#include "Sales_item.h"

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

Sales_item::Sales_item() : units_sold(0), revenue(0.00)
{
}

Sales_item::~Sales_item()
{
}
