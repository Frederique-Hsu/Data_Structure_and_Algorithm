/*!
 *  \file   binary_tree_node.hpp
 *  \brief  Define the structure of a binary tree node.
 *
 */

#pragma once

template<typename ObjType> struct BinaryTreeNode
{
    ObjType                     element;    // The data in the node
    BinaryTreeNode<ObjType>     *left;      // Left Child
    BinaryTreeNode<ObjType>     *right;     // Right Child
};
