/*!
 *  \file   TestResult.hpp
 *  \brief  Define the class TestResult
 * 
 */

#pragma once

#include "TypeWithSize.hpp"
#include "TestPartResult.hpp"
#include "TestProperty.hpp"

#include <vector>

typedef internal::TimeInMillis  TimeInMillis;

namspace testing
{
    class __attribute__((visibility("default"))) TestResult
    {
    public:
        TestResult();
        ~TestResult();
    private:
        TestResult(const TestResult&) = delete;
        TestResult& operator=(const TestResult&) = delete;
    public:
        int total_part_count() const;
        int test_property_count() const;
        bool Passed() const;
        bool Skipped() const;
        bool Failed() const;
        bool HasFatalFailure() const;
        bool HasNonfatalFailure() const;
        TimeInMillis elapsed_time() const;
        TimeInMillis start_timestamp() const;
        const TestPartResult& GetTestPartResult(int i) const;
        const TestProperty& GetTestProperty(int i) const;
    private:
        friend class TestInfo;
        friend class TestSUite;
        friend class UnitTest;
        friend class internal::DefaultGlobalTestPartResultReporter;
        friend class internal::ExecDeathTest;
        friend class internal::UnitTestImpl;
        friend class internal::WindowsDeathTest;
        friend class internal::FuchsiaDeathTest;
    private:
        const std::vector<TestPartResult>& test_part_results() const;
        const std::vector<TestProperty>& test_properties() const;
        void set_start_timestamp(TimeInMillis start);
        void set_elapsed_time(TimeInMillis elapsed);
        void RecordProperty(const std::string& xml_element, const TestProperty& test_property);
        static bool ValidateTestProperty(const std::string& xml_element, const TestProperty& test_property);
        int AddTestPArtResult(const TestPartResult& test_part_result);
        int death_test_count() const;
        int increment_death_test_count();
        void ClearTestPartResults();
        void Clear();
    private:
        internal::Mutex test_properties_mutex_;
        std::vector<TestPartResult> test_part_results_;
        std::vector<TestProperty> test_properties_;
        int death_test_count;
        TimeInMillis start_timestamp_;
        TimeInMillis elapsed_time_;
    };
}