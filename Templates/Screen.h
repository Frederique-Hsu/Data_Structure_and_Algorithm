#ifndef SCREEN_H
#define SCREEN_H

    #include <string>
    using namespace std;

    template<int hi, int wid>
    class Screen
    {
    public:
        Screen() : screen(hi * wid, '#'), cursor(0), height(hi), width(wid) {}
    private:
        string screen;
        string::size_type cursor;
        string::size_type height;
        string::size_type width;
    };

#endif  /* SCREEN_H */
