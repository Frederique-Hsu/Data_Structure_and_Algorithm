/*!
 *  \file   Test.hpp
 *  \brief  
 * 
 */

#pragma once

#include <string>
#include <memory>

namespace testing
{
    class __attribute__((visibility("default"))) Test
    {
        friend class TestInfo;
    public:
        virtual ~Test();
    private:
        TestInfo(const TestInfo&) = delete;
        TestInfo& operator=(const TestInfo&) = delete;
    protected:
        Test();
    public:
        static void SetUpTestSuite();
        static void TearDownTestSuite();
        static void TearDownTestCase();
        static void SetUpTestCase();
        static bool HasFatalFailure();
        static bool HasNonfatalFailure();
        static bool isSkipped();
        static bool HasFailure();
        static void RecordProperty(const std::string& key, const std::string& value);
        static void RecordProperty(const std::string& key, int value);
    protected:
        virtual void SetUp();
        virtual void TearDown();
    private:
        static bool HasSameFixtureClass();
        virtual void TestBody() = 0;
        void Run();
        void DeleteSelf_();
        const std::unique_ptr<::testing::internal::GTestFlagSaver> gtest_flag_saver_;

        struct Setup_should_be_spelled_SetUp 
        {
        };
        virtual Setup_should_be_spelled_SetUp* Setup();
    };
}