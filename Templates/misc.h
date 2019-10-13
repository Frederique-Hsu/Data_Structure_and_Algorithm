#ifndef MISC_H
#define MISC_H

    #include <cstddef>
    using namespace std;

    template<class Type>
    class Foo
    {
    public:
        static size_t count();
    private:
        static size_t ctr;
    };

/*====================================================================*/

    template<class Type> size_t Foo<Type>::ctr = 0;

    template<class Type> size_t Foo<Type>::count()
    {
        return ctr;
    }

#endif  /* MISC_H */
