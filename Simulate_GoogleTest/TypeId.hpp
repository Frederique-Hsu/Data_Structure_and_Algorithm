/*!
 *  \file   TypeId.hpp
 *  \brief  
 * 
 */

#pragma once

namespace testing
{
    namespace internal
    {
        typedef const void* TypeId;

        template<typename T> class TypeHelper
        {
        public:
            static bool dummy_;
        };

        template<typename T> TypeId GetTypeId();
        __attribute__((visibility("default"))) TypeId GetTestTypeId();

        template<typename T> bool TypeHelper<T>::dummy_ = false;

        template<typename T> TypeId GetTypeId()
        {
            return &(TypeHelper<T>::dummy_);
        }
    }
}