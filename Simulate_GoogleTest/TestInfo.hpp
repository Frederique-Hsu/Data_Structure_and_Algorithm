/*!
 *  \file   TestInfo.hpp
 *  \brief  Define the class TestInfo
 * 
 */

#pragma once

#include <string>
#include <memory>

#include "CodeLocation.hpp"
#include "TypeId.hpp"

class TestResult;

namespace testing
{
    class __attribute__((visibility("default"))) TestInfo
    {
    public:
        ~TestInfo();

    public:
        const char* test_suite_name() const;
        const char* test_case_name() const;
        const char* name() const;
        const char* type_param() const;
        const char* value_param() const;
        const char* file() const;
        int line() const;
        bool is_in_another_shard() const;
        bool should_run() const;
        bool is_reportable() const;
        const TestResult* result() const;
    private:
        friend class internal::DefaultDeathTestFactory;
        friend class Test;
        friend class TestSuite;
        friend class internal::UnitTestImpl;
        friend class internal::StreamingListenerTest;
        friend TestInfo* internal::MakeAndRegisterTestInfo(const char* test_suite_name,
                                                           const char* name,
                                                           const char* type_param,
                                                           const char* value_param,
                                                           internal::CodeLocation code_location,
                                                           internal::TypeId fixture_class_id,
                                                           internal::SetUpTestSuiteFunc set_up_tc,
                                                           internal::TearDownTestSuiteFunc tear_down_tc,
                                                           internal::TestFactoryBase* factory);
    private:
        TestInfo(const std::string& test_suite_name,
                 const std::string& name,
                 const char* a_type_param,
                 const char* a_value_param,
                 internal::CodeLocation a_code_location,
                 internal::TypeId fixture_class_id,
                 internal::TestFactoryBase* factory);
        TestInfo(const TestInfo&) = delete;
        TestInfo& operator=(const TestInfo&) = delete;
    private:
        int increment_death_test_count();
        void Run();
        static void ClearTestResult(TestInfo* test_info);
    private:
        const std::string test_suite_name_;
        const std::string name_;
        const std::unique_ptr<const ::std::string> type_param_;
        const std::unique_ptr<const ::std::string> value_param_;
        internal::CodeLocation location_;
        const internal::TypeId fixture_class_id_;
        bool should_run_;
        bool is_disabled_;
        bool matches_filter_;
        bool is_in_another_shard_;
        internal::TestFactoryBase* const factory_;
        TestResult result_;
    };

    namespace internal
    {
        using SetUpTestSuiteFunc = void (*)();
        using TearDownTestSuiteFunc = void (*)();
        
        __attribute__((visibility("default"))) TestInfo* MakeAndRegisterTestInfo(const char* test_suite_name,
                                                                                 const char* name,
                                                                                 const char* type_param,
                                                                                 const char* value_param,
                                                                                 CodeLocation code_location,
                                                                                 TypeId fixture_class_id,
                                                                                 SetUpTestSuiteFunc set_up_tc,
                                                                                 TearDownTestSuiteFunc tear_down_tc,
                                                                                 TestFactoryBase* factory);
    }
}