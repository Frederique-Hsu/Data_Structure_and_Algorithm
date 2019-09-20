#include "Screen.h"

Screen::Screen() : contents(""), cursor(0), height(0), width(0)
{
}

char Screen::get() const
{
    return contents[cursor];
}

char Screen::get(index ht, index wd) const
/* inline declared in the class declaration; no need to repeat on the implementation */
{
    index row = ht * width;     /* compute the row location */
    return contents[row + wd];  /* offset by wd to fetch specified character */
}

inline Screen::index Screen::get_cursor() const
/* not declared as inline inside the class declaration,
 * but OK to make inline definition
 */
{
    return cursor;
}

Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

Screen& Screen::move(index r, index c)
{
    index row = r * width;
    cursor = row + c;
    return *this;
}
