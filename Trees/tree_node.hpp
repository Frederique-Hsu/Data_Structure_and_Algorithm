/*!
 *  \file   tree_node.hpp
 *  \brief  Define the structure of a tree node.
 *
 */

#pragma once

template<typename ObjType>
struct TreeNode
{
    ObjType     element;
    TreeNode    *firstChild;
    TreeNode    *nextSibling;
};
