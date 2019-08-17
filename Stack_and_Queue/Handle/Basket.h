#ifndef BASKET_H
#define BASKET_H

	#include <set>

	class Sales_item;

	class Basket
	{
		/* type of the comparison function used to order the multiset*/
		typedef bool (*Comp)(const Sales_item&, const Sales_item&);
	public:
		typedef std::multiset<Sales_item, Comp> set_type;
		/* typedefs modeled after corresponding container types */
		typedef set_type::size_type size_type;
		typedef set_type::const_iterator const_iter;

		Basket();
		void add_item(const Sales_item& item);
		size_type size(const Sales_item& item) const;
		double total() const;	/* sum of net prices for all items in the basket */
	private:
		std::multiset<Sales_item, Comp> items;
	};

#endif	/* BASKET_H */