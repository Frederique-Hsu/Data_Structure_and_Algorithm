/*!
 *  \file       hash_functions.cpp
 *  \brief
 *
 */


#include "hash_functions.hpp"

#define HASH_METHOD_SIMPLE                      1
#define HASH_METHOD_NOT_SO_GOOD                 2
#define HASH_METHOD_HORNER_POLYNOMIAL_LAW       3
#define HASH_METHOD                     HASH_METHOD_HORNER_POLYNOMIAL_LAW


#if (HASH_METHOD == HASH_METHOD_SIMPLE)
    /*!
     *  \note   字符串的散列函数选择
     *          一种选择方法是把字符串的所有字符的ASCII码值集加起来
     */
    int hash(const std::string& key, int table_size)
    {
        int hash_value = 0;

        for (char ch : key)
        {
            hash_value += ch;
        }
        return hash_value % table_size;
    }
#elif (HASH_METHOD == HASH_METHOD_NOT_SO_GOOD)
    /*!
     *  \note   字符串散列函数选择
     *          另一种方法是： 假设Key至少有3个字符，值27表示英文字母表的字母外加一个空格的个数。
     *          而729是$27^2$. 该函数只考察前3个字符。
     */
    int hash(const std::string& key, int table_size)
    {
        return (key[0] + 27 * key[1] + 729 * key[2]) % table_size;
    }
#elif (HASH_METHOD == HASH_METHOD_HORNER_POLYNOMIAL_LAW)
    int hash(const std::string& key, int table_size)
    {
        int hash_value = 0;
        for (char ch : key)
        {
            hash_value += 37 * hash_value + ch;
        }
        return hash_value % table_size;
    }
#endif
