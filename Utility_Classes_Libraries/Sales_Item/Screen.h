#ifndef SCRREN_H
#define SCRREN_H

    #include <string>
    using namespace std;

    class Screen;   /* forward declaration */

    class Screen
    {
    public:
        Screen();

        typedef string::size_type index;
        char get() const;
        /* explicitly declared as inline; will be defined outside the class declaration */
        inline char get(index ht, index wd) const;
        /* inline not specified in class declaration, but can be defined inline later */
        index get_cursor() const;

        Screen& move(index row, index column);
        Screen& set(char);
        Screen& set(index, index, index);
    private:
        string contents;
        index cursor;
        index height;
        index width;
    };

    class LinkScreen
    {
        Screen window;
        LinkScreen* next;
        LinkScreen* prev;
    };

#endif  /* SCRREN_H */
