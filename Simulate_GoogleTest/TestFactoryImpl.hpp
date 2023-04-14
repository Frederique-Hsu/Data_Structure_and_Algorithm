/*!
 *  \file   TestFactoryImpl.hpp
 *  \brief  
 * 
 */

#pragma once

#include "TestFactoryBase.hpp"
#include "Test.hpp"

namespace testing
{
    namespace internal
    {
        template<class TestClass> class TestFactoryImpl : public TestFactoryBase
        {
        public:
            Test* CreateTest() override;
        }

        template<class TestClass> Test* TestFactoryImpl<TestClass>::CreateTest()
        {
            return new TestClass;
        }
    }
}