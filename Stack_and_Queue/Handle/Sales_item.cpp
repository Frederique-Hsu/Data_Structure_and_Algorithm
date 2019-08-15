#include "Sales_item.h"
#include "Item_base.h"
#include <stdexcept>

Sales_item::Sales_item() : p(0), use(new std::size_t(1))
{
}

Sales_item::Sales_item(const Sales_item& item) : p(item.p), use(item.use)
{
	++* use;
}

Sales_item::~Sales_item()
{
	decr_use();
}

Sales_item& Sales_item::operator=(const Sales_item& rhs)
{
	++* rhs.use;
	decr_use();
	p = rhs.p;
	use = rhs.use;
	return *this;
}

Sales_item::Sales_item(const Item_base& item) : p(item.clone()), use(new std::size_t(1))
{
}

const Item_base* Sales_item::operator->() const
{
	if (p)
	{
		return p;
	}
	else
	{
		throw std::logic_error("unbound Sales_item");
	}
}

const Item_base& Sales_item::operator*() const
{
	if (p)
	{
		return *p;
	}
	else
	{
		throw std::logic_error("unbound Sales_item");
	}
}

void Sales_item::decr_use()
{
	if (--*use == 0)
	{
		delete p;
		delete use;
	}
}

bool compare(const Sales_item& lhs, const Sales_item& rhs)
{
	return (lhs->clone() < rhs->clone());
}