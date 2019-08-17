#include "Query.h"
#include "Query_base.h"
#include "TextQuery.h"

Query::Query(Query_base* query) : q(query), use(new std::size_t(1))
{
}

Query::Query(const Query& c) : q(c.q), use(c.use)
{
	++* use;
}

void Query::decr_use()
{
	if (-- * use == 0)
	{
		delete q;
		delete use;
	}
}

Query::~Query()
{
	decr_use();
}

std::set<TextQuery::line_no> Query::eval(const TextQuery& t) const
{
	return q->eval(t);
}

std::ostream& Query::display(std::ostream& os) const
{
	return q->display(os);
}