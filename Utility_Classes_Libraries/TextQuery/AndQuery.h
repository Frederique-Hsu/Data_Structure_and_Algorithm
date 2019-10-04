#ifndef AND_QUERY_H
#define AND_QUERY_H

    #include "BinaryQuery.h"

    class AndQuery : public BinaryQuery
    {
        friend Query operator&(const Query&, const Query&);
    private:
        AndQuery(Query left, Query right);
        set<line_no> eval(const TextQuery& file) const;
    };

#endif  /* AND_QUERY_H */
