#ifndef LIST_H
#define LIST_H

    template<class elemType>
    class ListItem
    {
    private:
        ListItem(const elemType& elem);
    private:
        elemType element;
        ListItem* next;
    };

    template<class elemType>
    class List
    {
    public:
        List();
        List(const List& lst);
        List& operator=(const List& orig);
        ~List();
    public:
        void insert(ListItem<elemType>* ptr, elemType value);
        ListItem<elemType>* find(elemType value);
    private:
        ListItem<elemType>* front;
        ListItem<elemType>* end;
    };

    #include "List.cpp"

#endif  /* LIST_H */
