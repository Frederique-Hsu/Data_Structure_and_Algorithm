/*!
 *  \file   Swap.cpp
 *  \brief
 */

/*!
 *  \warning CANNOT include a header file in the same-name source file, which contains template. \n
 *           Otherwise it will occur the redefinition error.
 *
#include "Swap.hpp"
 *
 */

/* Macros */
#define SWAP_USING_3_COPIES         1
#define SWAP_USING_TYPE_CAST        2
#define SWAP_USING_MOVE_SEMANTICS   3
#define SWAP_USING_STD_LIB          4
#define SWAP                        SWAP_USING_MOVE_SEMANTICS


namespace My
{
    void swap(std::vector<std::string>& x, std::vector<std::string>& y)
    {
        using namespace std;
    #if (SWAP == SWAP_USING_3_COPIES)
        /* remember, if an object has a name, it is an lvalue */
        vector<string> tmp = x;
        x = y;
        y = tmp;
    #elif (SWAP == SWAP_USING_TYPE_CAST)
        /* use a cast to treat the right-hand-side as rvalue */
        vector<string> tmp = static_cast<vector<string>&&>(x);
        x = static_cast<vector<string>&&>(y);
        y = static_cast<vector<string>&&>(tmp);
    #elif (SWAP == SWAP_USING_MOVE_SEMANTICS)
        /* std::move converts any lvalue (or rvalue) into an rvalue */
        vector<string> tmp = std::move(x);
        x = std::move(y);
        y = std::move(tmp);
    #endif
    }
}
