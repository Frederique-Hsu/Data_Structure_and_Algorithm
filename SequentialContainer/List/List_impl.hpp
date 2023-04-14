/*!
 *  \file   List_impl.hpp
 *  \brief  Implement the List<T> container
 *
 */

/*! Implementation for \struct Node */
template<typename ObjType>
List<ObjType>::Node::Node(const ObjType& d,
                          List<ObjType>::Node *prevnode,
                          List<ObjType>::Node *nextnode)
    : data{d}, prev{prevnode}, next{nextnode}
{
}

template<typename ObjType>
List<ObjType>::Node::Node(ObjType&& d,
                          List<ObjType>::Node *prevnode,
                          List<ObjType>::Node *nextnode)
    : data{std::move(d)}, prev{prevnode}, next{nextnode}
{
}

/*============================================================================*/
/*! Implementation for \class const_iterator */
template<typename ObjType>
List<ObjType>::const_iterator::const_iterator() : current{nullptr}
{
}

template<typename ObjType>
List<ObjType>::const_iterator::const_iterator(List<ObjType>::Node *p) : current{p}
{
}

template<typename ObjType>
const ObjType& List<ObjType>::const_iterator::operator*() const
{
    return retrieve();
}

template<typename ObjType>
typename List<ObjType>::const_iterator& List<ObjType>::const_iterator::operator++()
{
    current = current->next;
    return *this;
}

template<typename ObjType>
typename List<ObjType>::const_iterator& List<ObjType>::const_iterator::operator+(int n)
{
    for (auto count = 0; count < n; ++count)
    {
        if (current == nullptr)
        {
            break;
        }
        else
        {
            current = current->next;
        }
    }
    return *this;
}

template<typename ObjType>
typename List<ObjType>::const_iterator List<ObjType>::const_iterator::operator++(int)
{
    const_iterator old = *this;
    ++(*this);
    return old;
}

template<typename ObjType>
typename List<ObjType>::const_iterator& List<ObjType>::const_iterator::operator--()
{
    current = current->prev;
    return *this;
}

template<typename ObjType>
typename List<ObjType>::const_iterator& List<ObjType>::const_iterator::operator-(int n)
{
    for (auto count = 0; count < n; ++count)
    {
        if (current == nullptr)
            break;
        else
            current = current->prev;
    }
    return *this;
}

template<typename ObjType>
typename List<ObjType>::const_iterator List<ObjType>::const_iterator::operator--(int)
{
    const_iterator old = *this;
    --(*this);
    return old;
}

template<typename ObjType>
bool List<ObjType>::const_iterator::operator==(const List<ObjType>::const_iterator& rhs) const
{
    return current == rhs.current;
}

template<typename ObjType>
bool List<ObjType>::const_iterator::operator!=(const List<ObjType>::const_iterator& rhs) const
{
    // return !(*this == rhs);
    return (current != rhs.current);
}

template<typename ObjType> ObjType& List<ObjType>::const_iterator::retrieve() const
{
    return current->data;
}

template<typename ObjType>
List<ObjType>::const_iterator::const_iterator(const List<ObjType>& lst,
                                              List<ObjType>::Node *p)
    : theList(&lst), current(p)
{
}

template<typename ObjType>
void List<ObjType>::const_iterator::assertIsValid() const
{
    if ( (theList == nullptr) || 
         (current == nullptr) ||
         (current == theList->head) )
    {
        throw IteratorOutOfBoundException();
    }
}

/*============================================================================*/
/* Implementation for \class iterator */
template<typename ObjType> List<ObjType>::iterator::iterator()
{
}

template<typename ObjType> List<ObjType>::iterator::iterator(List<ObjType>::Node *p)
    : List<ObjType>::const_iterator{p}
{
}

template<typename ObjType>
List<ObjType>::iterator::iterator(const List<ObjType>& lst, List<ObjType>::Node *p)
    : List<ObjType>::const_iterator(lst, p)
{
}

template<typename ObjType> ObjType& List<ObjType>::iterator::operator*()
{
    return const_iterator::retrieve();
}

template<typename ObjType>
const ObjType& List<ObjType>::iterator::operator*() const
{
    return const_iterator::operator*();
}

/*!
 *  \brief   perform the ++itr; action
 */
template<typename ObjType>
typename List<ObjType>::iterator& List<ObjType>::iterator::operator++()
{
    const_iterator::current = const_iterator::current->next;
    // this->current = this->current->next;
    return *this;
}

/*!
 *  \brief   perform the itr++; action
 */
template<typename ObjType>
typename List<ObjType>::iterator List<ObjType>::iterator::operator++(int)
{
    iterator old = *this;
    ++(*this);
    return old;
}

template<typename ObjType>
typename List<ObjType>::iterator& List<ObjType>::iterator::operator+(int n)
{
    for (auto count = 0; count < n; ++count)
    {
        if (const_iterator::current == nullptr)
            break;
        else
            const_iterator::current = const_iterator::current->next;
    }
    return *this;
}

template<typename ObjType>
typename List<ObjType>::iterator& List<ObjType>::iterator::operator--()
{
    const_iterator::current = const_iterator::current->prev;
    return *this;
}

template<typename ObjType>
typename List<ObjType>::iterator List<ObjType>::iterator::operator--(int)
{
    List<ObjType>::iterator old = *this;
    --(*this);
    return old;
}

template<typename ObjType>
typename List<ObjType>::iterator& List<ObjType>::iterator::operator-(int n)
{
    for (auto count = 0; count < n; ++count)
    {
        if (const_iterator::current == nullptr)
            break;
        else
            const_iterator::current = const_iterator::current->prev;
    }
    return *this;
}

/*============================================================================*/
/*! Implementation for \class List */
template<typename ObjType> List<ObjType>::List()
{
    init();
}

template<typename ObjType> List<ObjType>::~List()
{
    clear();
    delete head;
    delete tail;
}

template<typename ObjType> List<ObjType>::List(const List& rhs)
{
    init();
    for (auto& elem : rhs)
    {
        push_back(elem);
    }
}

template<typename ObjType>
List<ObjType>& List<ObjType>::operator=(const List& rhs)
{
    List copy = rhs;
    std::swap(*this, copy);
    return *this;
}

template<typename ObjType> List<ObjType>::List(List&& rhs)
    : m_size{rhs.m_size}, head{rhs.head}, tail{rhs.tail}
{
    rhs.m_size = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

template<typename ObjType> List<ObjType>& List<ObjType>::operator=(List&& rhs)
{
    std::swap(m_size, rhs.m_size);
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);

    return *this;
}

template<typename ObjType> void List<ObjType>::init()
{
    m_size = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

template<typename ObjType>
typename List<ObjType>::iterator List<ObjType>::begin()
{
    return head->next;
}

template<typename ObjType>
typename List<ObjType>::const_iterator List<ObjType>::begin() const
{
#if defined(ENABLE_ITERATOR_ERROR_CHECKING)
    List<ObjType>::const_iterator itr(*this, head);
    return ++itr;
#else
    return head->next;
#endif
}

template<typename ObjType>
typename List<ObjType>::iterator List<ObjType>::end()
{
    return tail;
}

template<typename ObjType>
typename List<ObjType>::const_iterator List<ObjType>::end() const
{
    return tail;
}

template<typename ObjType> int List<ObjType>::size() const
{
    return m_size;
}

template<typename ObjType> bool List<ObjType>::empty() const
{
    return (size() == 0);
}

template<typename ObjType> void List<ObjType>::clear()
{
    while (!empty())
    {
        pop_front();
    }
}

template<typename ObjType> ObjType& List<ObjType>::front()
{
    return *begin();
}

template<typename ObjType> const ObjType& List<ObjType>::front() const
{
    return *begin();
}

template<typename ObjType> ObjType& List<ObjType>::back()
{
    return *--end();
}

template<typename ObjType> const ObjType& List<ObjType>::back() const
{
    return *--end();
}

template<typename ObjType> void List<ObjType>::push_front(const ObjType& obj)
{
    insert(begin(), obj);
}

template<typename ObjType> void List<ObjType>::push_front(ObjType&& obj)
{
    insert(begin(), std::move(obj));
}

template<typename ObjType> void List<ObjType>::push_back(const ObjType& obj)
{
    insert(end(), obj);
}

template<typename ObjType> void List<ObjType>::push_back(ObjType&& obj)
{
    insert(end(), std::move(obj));
}

template<typename ObjType> void List<ObjType>::pop_front()
{
    erase(begin());
}

template<typename ObjType> void List<ObjType>::pop_back()
{
    erase(--end());
}

#if defined(ENABLE_ITERATOR_ERROR_CHECKING)
    template<typename ObjType>
    typename List<ObjType>::iterator List<ObjType>::insert(List<ObjType>::iterator itr,
                                                           const ObjType& obj)
    {
        itr.assertIsValid();
        if (itr.theList != this)
        {
            throw IteratorMismatchException();
        }
        List<ObjType>::Node *currentNode = itr.current;
        List<ObjType>::Node *nextNode = currentNode->next;
        List<ObjType>::Node *prevNode = currentNode->prev;
        List<ObjType>::Node *newNode = new List<ObjType>::Node(obj,
                                                               prevNode,
                                                               currentNode);
        m_size++;

        prevNode->next = newNode;
        currentNode->prev = newNode;
        return List<ObjType>::iterator(*this, newNode);
    }
#else
    template<typename ObjType>      /*! \note Insert obj before itr */
    typename List<ObjType>::iterator List<ObjType>::insert(List<ObjType>::iterator itr,
                                                           const ObjType& obj)
    {
    #if 0
        List<ObjType>::Node *p = itr.current;
        m_size++;
        return { p->prev = p->prev->next = new Node(obj, p->prev, p) };
    #else
        List<ObjType>::Node *newNode = new List<ObjType>::Node(obj, nullptr, nullptr);
        ++m_size;
        List<ObjType>::Node *prevNode = itr.current->prev;

        newNode->prev = prevNode;
        newNode->next = itr.current;
        itr.current->prev = prevNode;
        prevNode->next = newNode;
        return List<ObjType>::iterator(newNode);
    #endif
    }
#endif

template<typename ObjType>      /*! \note Insert obj before itr */
typename List<ObjType>::iterator List<ObjType>::insert(List<ObjType>::iterator itr,
                                                       ObjType&& obj)
{
    List<ObjType>::Node *currentNode = itr.current;
    List<ObjType>::Node *prevNode = currentNode->prev;
    List<ObjType>::Node *newNode = new List<ObjType>::Node(std::move(obj),
                                                           prevNode,
                                                           currentNode);
    ++m_size;
    prevNode->next = newNode;
    currentNode->prev = newNode;
    return List<ObjType>::iterator(newNode);
}

template<typename ObjType>      /*! Erase item at itr */
typename List<ObjType>::iterator List<ObjType>::erase(List<ObjType>::iterator itr)
{
    List<ObjType>::Node *currentNode = itr.current;
    List<ObjType>::Node *prevNode = currentNode->prev;
    List<ObjType>::Node *nextNode = currentNode->next;

    List<ObjType>::iterator retItr(nextNode);
    delete currentNode;
    m_size--;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    return retItr;
}

template<typename ObjType>
typename List<ObjType>::iterator List<ObjType>::erase(List<ObjType>::iterator from,
                                                      List<ObjType>::iterator to)
{
    for (List<ObjType>::iterator itr = from; itr != to; )
    {
        itr = erase(itr);
    }
    return to;
}
