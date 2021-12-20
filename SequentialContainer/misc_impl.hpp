/*!
 *  \file   misc_impl.hpp
 *  \brief  Make the implementation for misc.
 *
 */

#include <iterator>

template<typename Container> void removeEveryOtherItem(Container& lst)
{
    auto itr = lst.begin();
    while (itr != lst.end())
    {
        itr = lst.erase(itr);
        if (itr != lst.end())
        {
            ++itr;
        }
    }
}

template<typename Container, typename ObjectType> void change(Container& container,
                                                              const ObjectType& newValue)
{
    typename Container::iterator itr = container.begin();
    while (itr != container.end())
    {
        *itr++ = newValue;
    }
}

namespace My
{
    template<typename Container> auto begin(Container& container) -> decltype(container.begin())
    {
        return container.begin();
    }

    template<typename Container> auto begin(const Container& container) -> decltype(container.begin())
    {
        return container.begin();
    }

    template<typename Container> auto end(Container& container) -> decltype(container.end())
    {
        return container.end();
    }

    template<typename Container> auto end(const Container& container) -> decltype(container.end())
    {
        return container.end();
    }
}
/*!
 *  \brief  Printing out any container
 */
template<typename Container> void print(const Container& container, std::ostream& out)
{
#define STD_BEGIN_END           1
#define USER_DEFINED_BEGIN_END  2
#define USE                     USER_DEFINED_BEGIN_END

#if 0
    typename Container::iterator itr = container.begin();
    while (itr != container.end())
    {
        out << *itr << std::endl;
        ++itr;
    }
#else
    if (container.empty())
        out << "(empty)";
    else
    {
        /* Even if the container user defined may not has iterator begin() method,
         * std::begin(container) also can create an iterator for that container.
         * So does std::end(container).
         */
#if (USE == STD_BEGIN_END)
        auto itr = std::begin(container);
#elif (USE == USER_DEFINED_BEGIN_END)
        auto itr = My::begin(container);
#endif
        out << "[ " << *itr++;      /* Print first item */
#if (USE == STD_BEGIN_END)
        while (itr != std::end(container))
#elif (USE == USER_DEFINED_BEGIN_END)
        while (itr != My::end(container))
#endif
        {
            out << ", " << *itr++;
        }
        out << " ]" << std::endl;
    }
#endif
}
