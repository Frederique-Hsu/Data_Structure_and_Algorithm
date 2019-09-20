#include "misc.h"

Record::Record() : byte_count(0)
{
}

Record::Record(Record::size s) : byte_count(s)
{
}

Record::Record(std::string s) : byte_count(0), name(s)
{
}

Record::size Record::get_count() const
{
    return byte_count;
}

std::string Record::get_name() const
{
    return name;
}
