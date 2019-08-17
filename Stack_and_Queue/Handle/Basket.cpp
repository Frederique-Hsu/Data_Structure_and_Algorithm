#include "Basket.h" 
#include "Sales_item.h"
#include "Item_base.h"

Basket::Basket() : items(compare)	/* initialize the comparator */
{
}

void Basket::add_item(const Sales_item& item)
{
	items.insert(item);
}

Basket::size_type Basket::size(const Sales_item& item) const
{
	return items.count(item);
}

double Basket::total() const
{
	double sum = 0.0;
	/* find each set of items with the same ISBN and calculate
	 * the net price for that quantity of items. 
	 * iter refers to first copy of each book in the set 
	 * upper_bound refers to next element with a different ISBN.
	 */
	for (const_iter iter = items.begin();
		iter != items.end();
		iter = items.upper_bound(*iter))
	{
		sum += (*iter)->net_price(items.count(*iter));
	}
	return sum;
}