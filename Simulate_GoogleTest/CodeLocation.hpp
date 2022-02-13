/*!
 *  \file   CodeLocation.hpp
 *  \brief  Define a simple structure.
 * 
 */

#include <string>

namespace testing
{
    namespace internal
    {
        struct CodeLocation
        {
            CodeLocation(const std::string& a_file, int a_line);
            std::string file;
            int line;
        };

        CodeLocation::CodeLocation(const std::string& a_file, int a_line) : file(a_file), line(a_line)
        {
        }
    }
}