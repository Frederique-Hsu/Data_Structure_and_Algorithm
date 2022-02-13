/*!
 *  \file   TestFactoryBase.hpp
 *  \brief  
 * 
 */

#pragma once

namespace testing
{
    namespace internal
    {
        class testing::Test;

        class TestFactoryBase
        {
        public:
            virtual ~TestFactoryBase();
        protected:
            TestFactoryBase();
        private:
            TestFactoryBase(const TestFactoryBase&) = delete;
            TestFactoryBase& operator=(const TestFactoryBase&) = delete;
        public:
            virtual testing::Test* CreateTest() = 0;
        };
    }
}