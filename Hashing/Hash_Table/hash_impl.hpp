/*!
 *  \file       hash_impl.hpp
 *  \brief
 *
 */


template<typename Key>
size_t hash<Key>::operator()(const Key& key) const
{
    return key;     // 线性探测法
}

size_t hash<std::string>::operator()(const std::string& key) const
{
    size_t hashValue = 0;

    for (char letter : key)
    {
        hashValue = 37 * hashValue + letter;
    }
    return hashValue;
}

size_t hash<Employee>::operator()(const Employee& item) const
{
    static hash<std::string> hash_fn;
    return hash_fn(item.getName());
}
