#include "Item_base.h"

Item_base::Item_base(const std::string& book, double sales_price)
{
	isbn = book;
	price = sales_price;
}

std::string Item_base::book() const
{
	return isbn;
}

double Item_base::net_price(std::size_t n) const
{
	return n * price;
}

Item_base* Item_base::clone() const
{
	return (new Item_base(*this));
}

void print_total(std::ostream& os, const Item_base& item, std::size_t n)
{
	os << "ISBN: " << item.book()
		<< "\tnumber sold: " << n
		<< "\ttotal price: " << item.net_price(n)
		<< std::endl;
}

Bulk_item::Bulk_item() : min_qty(0), discount(0.0)
{
}

Bulk_item::Bulk_item(const std::string& book,
	double sales_price,
	std::size_t qty,
	double disc_rate) : Item_base(book, sales_price)
{
	min_qty = qty;
	discount = disc_rate;
}

Bulk_item* Bulk_item::clone() const
{
	return (new Bulk_item(*this));
}

double Bulk_item::net_price(std::size_t cnt) const
{
	if (cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

Disc_item::Disc_item(const std::string& book,
	double sales_price,
	std::size_t qty,
	double disc_rate) : Item_base(book, sales_price), 
	quantity(qty), discount(disc_rate)
{
}

std::pair<std::size_t, double> Disc_item::discount_policy() const
{
	return std::make_pair(quantity, discount);
}

Disc_item* Disc_item::clone() const
{
	return (new Disc_item(*this));
}

double Disc_item::net_price(std::size_t n) const
{
	if (n >= quantity)
		return quantity * price + (n - quantity) * (1 - discount) * price;
	else
		return quantity * (1 - discount) * price;
}
