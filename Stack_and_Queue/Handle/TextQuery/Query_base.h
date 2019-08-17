#ifndef QUERY_BASE_H
#define QUERY_BASE_H

	#include <set>
	#include <iostream>

	#include "TextQuery.h"

	class Query;

	/* private, abstract class acts as a base class for concrete query types */
	class Query_base
	{
		friend class Query;
	protected:
		typedef TextQuery::line_no line_no;
		virtual ~Query_base();
	private:
		/* eval - returns the |set| of lines that this Query matches */
		virtual std::set<line_no> eval(const TextQuery&) const = 0;
		/* display - prints the query */
		virtual std::ostream& display(std::ostream & = std::cout) const = 0;
	};

#endif	/* QUERY_BASE_H */
