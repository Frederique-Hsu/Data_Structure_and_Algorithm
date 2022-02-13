/*!
 *  \file   TestInfo.cpp
 *  \brief  Implement the class TestInfo.
 * 
 */

#include "TestInfo.hpp"

namespace testing
{
    const char* TestInfo::test_suite_name() const
    {
        return test_suite_name_.c_str();
    }

    const char* TestInfo::test_case_name() const
    {
        return test_suite_name();
    }

    const char* TestInfo::name() const
    {
        return name_.c_str();
    }

    const char*TestInfo::type_param() const
    {
        if (type_param_.get() != nullptr)
        {
            return type_param_->c_str();
        }
        return nullptr;
    }

    const char* TestInfo::value_param() const
    {
        if (value_param_.get() != nullptr)
        {
            return value_param_->c_str();
        }
        return nullptr;
    }

    consr char* TestInfo::file() const
    {
        return location_.file.c_str();
    }

    int TestInfo::line() const
    {
        return location_.line;
    }

    bool TestInfo::is_in_another_shard() const
    {
        return is_in_another_shard_;
    }

    bool TestInfo::should_run() const
    {
        return should_run_;
    }

    bool TestInfo::is_reportable() const
    {
        return matches_filter_ && !is_in_another_shard_;
    }
}