#ifndef LIST_H
#define LIST_H

    /* Forward declarations */
    template<class elemType> class ListItem;
    template<class elemType> class List;

    /* class templates definition */
    template<class elemType> class ListItem
    {
        friend class List<elemType>;
    private:
        ListItem(const elemType& elem);
    private:
        elemType item;
        ListItem *next;
    };

    template<class elemType> class List
    {
    public:
        List();
        List(const List&);
        List& operator=(const List&);
        ~List();
    public:
        void insert(ListItem<elemType> *ptr, elemType value);
        ListItem<elemType> *find(elemType value);
    private:
        ListItem<elemType> *front;
        ListItem<elemType> *end;
    };

/*=================================================================================================*/

    template<class elemType> ListItem<elemType>::ListItem(const elemType& elem) : item(elem), next(0)
    {
    }

    template<class elemType> List<elemType>::List() : front(0), end(0)
    {
    }

    template<class elemType> List<elemType>::List(const List& lst)
    {
        if (lst.front == 0)
        {
            front = 0;
            end = 0;
        }
        else
        {
            front = new ListItem<elemType>(lst.front->item);
            end = front;
            ListItem<elemType> *pnode = lst.front;
            do
            {
                pnode = pnode->next;
                if (pnode == 0)
                    break;
                end->next = new ListItem<elemType>(pnode->item);
                end = end->next;
            }
            while (1);
        }
    }

    template<class elemType> List<elemType>& List<elemType>::operator=(const List& orig)
    {
        if (orig.front == 0)
        {
            front = 0;
            end = 0;
        }
        else
        {
            front = new ListItem<elemType>(orig.front->item);
            end = front;
            ListItem<elemType> *pnode = orig.front;
            do
            {
                pnode = pnode->next;
                if (pnode == 0)
                    break;
                end->next = new ListItem<elemType>(pnode->item);
                end = end->next;
            }
            while (1);
        }
        return *this;
    }

    template<class elemType> List<elemType>::~List()
    {
        ListItem<elemType> *pnode = front;
        while (pnode != 0)
        {
            ListItem<elemType> *ptemp = pnode->next;
            delete pnode;
            pnode = ptemp;
        }
    }

    template<class elemType> void List<elemType>::insert(ListItem<elemType> *ptr, elemType value)
    {
        ListItem<elemType> *pnode = front;
        while (pnode != 0)
        {
            if (pnode == ptr)
            {
                ListItem<elemType> *newNode = new ListItem<elemType>(value);
                newNode->next = pnode->next;
                pnode->next = newNode;
                return;
            }
            pnode = pnode->next;
        }
    }

    template<class elemType> ListItem<elemType>* List<elemType>::find(elemType value)
    {
        ListItem<elemType> *pnode = front;
        while (pnode != 0)
        {
            if (pnode->item == value)
            {
                return pnode;
            }
            pnode = pnode->next;
        }
        return 0;
    }

#endif  /* LIST_H */