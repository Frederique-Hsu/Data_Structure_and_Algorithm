/*!
 *  \file   Vector.cpp
 *  \brief  Implement the class template Vector<T>
 *  \author Frederique Hsu
 *  \date   Sun.    19 Dec. 2021
 *
 */

template<typename ObjType> const int Vector<ObjType>::SPARE_CAPACITY = 16;

template<typename ObjType> Vector<ObjType>::Vector(int initSize) : m_size(initSize),
                                                                   m_capacity(initSize + SPARE_CAPACITY)
{
    m_objects = new ObjType[m_capacity];
}

template<typename ObjType> Vector<ObjType>::~Vector()
{
    delete [] m_objects;
}

template<typename ObjType> Vector<ObjType>::Vector() : m_size(0), m_capacity(SPARE_CAPACITY)
{
    m_objects = nullptr;
}

template<typename ObjType> Vector<ObjType>::Vector(const Vector& rhs) : m_size(rhs.m_size),
                                                                        m_capacity(rhs.m_capacity),
                                                                        m_objects(nullptr)
{
    m_objects = new ObjType[m_capacity];
    for (int index = 0; index < m_size; ++index)
    {
        m_objects[index] = rhs.m_objects[index];
    }
}

template<typename ObjType> Vector<ObjType>& Vector<ObjType>::operator=(const Vector& rhs)
{
    Vector copy = rhs;
    std::swap(*this, copy);
    return *this;
}

template<typename ObjType> Vector<ObjType>::Vector(Vector&& rhs) : m_size(rhs.m_size),
                                                                   m_capacity(rhs.m_capacity),
                                                                   m_objects(rhs.m_objects)
{
    rhs.m_objects = nullptr;
    rhs.m_size = 0;
    rhs.m_capacity = 0;
}

template<typename ObjType> Vector<ObjType>& Vector<ObjType>::operator=(Vector&& rhs)
{
    std::swap(m_size, rhs.m_size);
    std::swap(m_capacity, rhs.m_capacity);
    std::swap(m_objects, rhs.m_objects);
    return *this;
}

template<typename ObjType> void Vector<ObjType>::resize(int newSize)
{
    if (newSize > m_capacity)
    {
        reserve(newSize * 2);
    }
    m_size = newSize;
}

template<typename ObjType> void Vector<ObjType>::reserve(int newCapacity)
{
    if (newCapacity < m_size)
        return;

    ObjType* newArray = new ObjType[newCapacity];
    for (int index = 0; index < m_size; ++index)
    {
        newArray[index] = std::move(m_objects[index]);
    }
    m_capacity = newCapacity;
    std::swap(m_objects, newArray);
    delete [] newArray;
}

template<typename ObjType> ObjType& Vector<ObjType>::operator[](int index)
{
    return m_objects[index];
}

template<typename ObjType> const ObjType& Vector<ObjType>::operator[](int index) const
{
    return m_objects[index];
}

template<typename ObjType> bool Vector<ObjType>::empty() const
{
    return (m_size == 0);
}

template<typename ObjType> int Vector<ObjType>::size() const
{
    return m_size;
}

template<typename ObjType> int Vector<ObjType>::capacity() const
{
    return m_capacity;
}

template<typename ObjType> void Vector<ObjType>::push_back(const ObjType& obj)
{
    if (m_size == m_capacity)
    {
        reserve(2 * m_capacity + 1);
    }
    m_objects[m_size++] = obj;
}

template<typename ObjType> void Vector<ObjType>::push_back(ObjType&& obj)
{
    if (m_size == m_capacity)
    {
        reserve(2 * m_capacity + 1);
    }
    m_objects[m_size++] = std::move(obj);
}

template<typename ObjType> void Vector<ObjType>::pop_back()
{
    --m_size;
}

template<typename ObjType> const ObjType& Vector<ObjType>::back() const
{
    return m_objects[m_size-1];
}

template<typename ObjType> typename Vector<ObjType>::iterator Vector<ObjType>::begin()
{
    return &(m_objects[0]);
}

template<typename ObjType> typename Vector<ObjType>::const_iterator Vector<ObjType>::begin() const
{
    return &(m_objects[0]);
}

template<typename ObjType> typename Vector<ObjType>::iterator Vector<ObjType>::end()
{
    return &(m_objects[size()]);
}

template<typename ObjType> typename Vector<ObjType>::const_iterator Vector<ObjType>::end() const
{
    return &(m_objects[size()]);
}

