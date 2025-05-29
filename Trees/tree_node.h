/*!
 *  \file       tree_node.h
 *  \brief      Define the general structure of tree node.
 *
 */


#pragma once


typedef struct TreeNode     *PtrToNode;
typedef struct PtrToNode    Tree;


struct TreeNode
{
    ElementType     Element;
    Tree            Left;
    Tree            Right;
};
