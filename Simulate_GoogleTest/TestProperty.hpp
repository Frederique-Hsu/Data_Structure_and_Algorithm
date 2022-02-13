/*!
 *  \file   TestProperty.hpp
 *  \brief  
 * 
 */

#pragma once

#include <string>

namespace testing
{
    class TestProperty
    {
    public:
        TestProperty(const std::string& a_key, const std::string& a_value);
    private:
        std::string key_;
        std::string value_;
    public:
        const char* key() const;
        const char* value() const;
        void SetValue(const std::string& new_value);
    };
}