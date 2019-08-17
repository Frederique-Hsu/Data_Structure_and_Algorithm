#ifndef SALES_ITEM_H
#define SALES_ITEM_H

	#include <iostream>
	#include <set>

	class Item_base;

	/* Use counted handle class for the Item_base hierarchy */
	class Sales_item
	{
	public:
		/* default constructor : unbound handle */
		Sales_item();
		/* copy control members to manager the use count and pointers */
		Sales_item(const Sales_item& item);
		/* attaches a handle to a copy of the Item_base object */
		Sales_item(const Item_base& item);
		~Sales_item();

		Sales_item& operator=(const Sales_item& item);
		/* member access operators */
		const Item_base* operator->() const;
		const Item_base& operator*() const;
	private:
		Item_base* p;		/* pointer to shared item */
		std::size_t* use;	/* pointer to shared use count */
		/* called by both destructor and assignment operator to free pointers */
		void decr_use();
	};

	/* compare defines item ordering for the multiset in Basket */
	bool compare(const Sales_item& lhs, const Sales_item& rhs);

#endif	/* SALES_ITEM_H */