#ifndef ITEM_BASE_H
#define ITEM_BASE_H

	#include <string>
	#include <iostream>

	class Item_base
	{
	public:
		Item_base(const std::string& book = "", double sales_price = 0.0);
		virtual ~Item_base() {}
		std::string book() const;

		virtual Item_base* clone() const;
		virtual double net_price(std::size_t n) const;
	private:
		std::string isbn;
	protected:
		double price;
	};

	void print_total(std::ostream& os, const Item_base& item, std::size_t n);

	class Bulk_item : public Item_base
	{
	public:
		Bulk_item();
		Bulk_item(const std::string& book, 
			      double sales_price, 
			      std::size_t qty = 0, 
			      double disc_rate = 0.0);
		double net_price(std::size_t cnt) const;
		Bulk_item* clone() const;
	private:
		std::size_t min_qty;
		double discount;
	};

	class Disc_item : public Item_base
	{
	public:
		Disc_item(const std::string& book = "", 
			      double sales_price = 0.0,
			      std::size_t qty = 0,
			      double disc_rate = 0.0);
		Disc_item* clone() const;
		double net_price(std::size_t n) const;
		std::pair<std::size_t, double> discount_policy() const;
	protected:
		std::size_t quantity;
		double discount;
	};

#endif	/* ITEM_BASE_H */