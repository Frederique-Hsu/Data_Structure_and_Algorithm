#ifndef QUERY_H
#define QUERY_H

	#include <string>
	#include <set>

	#include "TextQuery.h"

	class Query_base;

	/* handle class to manage the Query_base inheritance hierarchy */
	class Query
	{
		/* these operators need access to the Query_base* constructor */
		friend Query operator~(const Query&);	/* NotQuery */
		friend Query operator|(const Query&, const Query&);		/* OrQuery */
		friend Query operator&(const Query&, const Query&);		/* AndQuery */
	public:
		Query(const std::string&);		/* builds a new WordQuery */
		/* copy control to manage pointers and use counting */
		Query(const Query& c);
		~Query();
		Query& operator=(const Query&);

		/* interface functions : will call corresponding Query_base operators */
		std::set<TextQuery::line_no> eval(const TextQuery& t) const;
		std::ostream& display(std::ostream& os) const;
	private:
		Query(Query_base* query);
		Query_base* q;
		std::size_t* use;
		void decr_use();
	};

#endif	/* QUERY_H */