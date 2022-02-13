/*!
 *  \file   gtest.hpp
 *  \brief  Simulate the GoogleTest framework.
 * 
 */

#pragma once

#include "TestInfo.hpp"
#include "CodeLocation.hpp"
#include "SuiteApiResolver.hpp"
#include "TestFactoryImpl.hpp"

namespace testing
{
    #define GTEST_STRINGIFY_(name)  #name

    #define GTEST_TEST_CLASS_NAME_(test_suite_name, test_name) test_suite_name##_##test_name##_Test

    #define GTEST_DISALLOW_ASSIGN_(type)            \
        type operator=(type const &) = delete

    #define GTEST_DISALLOW_COPY_AND_ASSIGN_(type)   \
        type(type const &) = delete;                \
        GTEST_DISALLOW_ASSIGN_(type)

    /*================================================================================================*/

    class parent_class;
    class ::testing::TestInfo;

    /*================================================================================================*/
    

    #define GTEST_TEST_(test_suite_name, test_name, parent_class, parent_id)                                                                                \
        static_assert(sizeof(GTEST_STRINGIFY_(test_suite_name)) > 1, "test_suite_name must not be empty");                                                  \
                                                                                                                                                            \
        static_assert(sizeof(GTEST_STRINGIFY_(test_name)) > 1, "test_name must not be empty");                                                              \
                                                                                                                                                            \
        class GTEST_TEST_CLASS_NAME_(test_suite_name, test_name) : public parent_class                                                                      \
        {                                                                                                                                                   \
        public:                                                                                                                                             \
            GTEST_TEST_CLASS_NAME_(test_suite_name, test_name)()                                                                                            \
            {                                                                                                                                               \
            }                                                                                                                                               \
        private:                                                                                                                                            \
            virtual void TestBody();                                                                                                                        \
            static ::testing::TestInfo* const test_info_ __attribute__((unused));                                                                           \
            GTEST_DISALLOW_COPY_AND_ASSIGN_(GTEST_TEST_CLASS_NAME_(test_suite_name, test_name));                                                            \
        };                                                                                                                                                  \
                                                                                                                                                            \
        ::testing::TestInfo* const GTEST_TEST_CLASS_NAME_(test_suite_name, test_name)::test_info_ =                                                         \
        ::testing::internal::MakeAndRegisterTestInfo(#test_suite_name,                                                                                      \
                                                     #test_name,                                                                                            \
                                                     nullptr,                                                                                               \
                                                     nullptr,                                                                                               \
                                                     ::testing::internal::CodeLocation(__FILE_, __LINE__),                                                  \
                                                     (parent_id),                                                                                           \
                                                     ::testing::internal::SuiteApiResolver<parent_class>::GetSetUpCaseOrSuite(__FILE__, __LINE__),          \
                                                     ::testing::internal::SuiteApiResolver<parent_class>::GetTearDownCaseOrSuite(__FILE__, __LINE__),       \
                                                     new ::testing::internal::TestFactoryImpl<GTEST_TEST_CLASS_NAME_(test_suite_name, test_name)>           \
                                                    );                                                                                                      \
                                                                                                                                                            \
        void GTEST_TEST_CLASS_NAME_(test_suite_name, test_name)::TestBody()                                                                                 \


    #define TEST_F(test_fixture, test_name) GTEST_TEST_(test_fixture, test_name, test_fixture, ::testing::internal::GetTypeId<test_fixture>())

}   