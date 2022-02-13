/*!
 *  \file   TestPartResult.hpp
 *  \brief  
 * 
 */

#pragma once

#include <string>
#include <iostream>

namespace testing
{
    class __attribute__((visibility("default"))) TestPartResult
    {
    public:
        enum Type
        {
            kSuccess,
            kNonFatalFailure,
            kFatalFailure,
            kSkip
        };

        TestPartResult(Type a_type,
                       const char* a_file_name,
                       int a_line_number,
                       const char* a_message);
    public:
        Type type() const;
        const char* file_name() const;
        int line_number() const;
        const char* summary() const;
        const char* message() const;
        bool skipped() const;
        bool passed() const;
        bool nonfatally_failed() const;
        bool fatally_failed() const;
        bool failed() const;
    private:
        Type type_;
        static std::string ExtractSummary(const char* message);
        std::string file_name_;
        int line_number_;
        std::string summary_;
        std::string message_;
    };

    std::ostream& operator<<(std::ostream& os, const TestPartResult& result);
}