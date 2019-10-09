#ifndef LIST_H
#define LIST_H

    #include <iostream>
    using namespace std;

    template<class elemType> class ListItem;
    template<class elemType> class List;

    template<class elemType> ostream& operator<<(ostream& out, const List<elemType>& lst);
    template<class elemType> istream& operator>>(istream& in, List<elemType>& lst);

    /*============================================================================================*/

    template<class elemType>
    class ListItem
    {
        friend class List<elemType>;
        friend ostream& operator<< <elemType> (ostream& out, const List<elemType>& lst);
    private:
        ListItem(const elemType& elem);
        ~ListItem();
    private:
        elemType element;
        ListItem* next;
    };

    /*============================================================================================*/

    template<class elemType>
    class List
    {
        friend ostream& operator<< <elemType> (ostream& out, const List<elemType>& lst);
    public:
        List();
        List(const List& lst);
        List& operator=(const List& orig);
        ~List();
    public:
        template<class Iter> List(Iter begin, Iter end);
        template<class Iter> void assign(Iter begin, Iter end);
    public:
        void insert(ListItem<elemType>* ptr, elemType value);
        void insert(unsigned atPos, elemType element);
        ListItem<elemType>* find(elemType value);
        void append(elemType element);
        bool isEmpty() const;
        void remove(unsigned atPos);
        unsigned count() const;
    private:
        ListItem<elemType>* front;
        ListItem<elemType>* end;
    private:
        void destroy();
    };

    /*============================================================================================*/

    #include "List.cpp"

#endif  /* LIST_H */
