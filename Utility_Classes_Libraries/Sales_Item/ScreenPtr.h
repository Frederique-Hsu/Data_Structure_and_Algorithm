#ifndef SCREENPTR_H
#define SCREENPTR_H

    #include <string>
    using namespace std;

    class Screen;
    class ScreenPtr;

    class ScrPtr
    {
        friend class ScreenPtr;
    private:
        Screen* sp;
        size_t use;
    private:
        ScrPtr(Screen* p);
        ~ScrPtr();
    };

    /* smart pointer: Users pass to a pointer to a dynamically allocated Screen,
     *                which is automatically destroyed when the last ScreenPtr goes away.
     */
    class ScreenPtr
    {
    public:
        /* no default constructor: ScreenPtr must be bound to an object. */
        ScreenPtr(Screen* p);
        ScreenPtr(const ScreenPtr& orig);
        ScreenPtr& operator=(const ScreenPtr& orig);
        ~ScreenPtr();
    public:
        Screen& operator*();
        Screen* operator->();
        const Screen& operator*() const;
        const Screen* operator->() const;
    private:
        ScrPtr* ptr;
    };

#endif  /* SCREENPTR_H */
