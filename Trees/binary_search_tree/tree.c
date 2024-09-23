/*!
 *  \file       tree.c
 *  \brief      Implement the binary search tree.
 *
 */


#include "tree.h"

#include <stdlib.h>

struct TreeNode
{
    ElementType     element;
    SearchTree      left;
    SearchTree      right;
};

/*!
 *  \brief          建立一颗空树
 *  \param[in, out] tree - 一颗树的根
 *  \return         NULL - 一颗空树
 */
SearchTree MakeEmpty(SearchTree tree)
{
    if (tree != NULL)
    {
        MakeEmpty(tree->left);
        MakeEmpty(tree->right);
        free(tree);
    }
    return NULL;
}

/*!
 *  \brief      Find a specific element from a tree
 *  \param[in]  elem - user-specified element
 *  \param[in]  tree - a binary search tree, pointer to the root node.
 *  \return     the pointer to the tree node whose element is identical to the elem.
 *  \note
 */
Position Find(ElementType elem, SearchTree tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if (elem < tree->element)
    {
        return Find(elem, tree->left);
    }
    else if (tree->element < elem)
    {
        return Find(elem, tree->right);
    }
    else    /* elem == tree->element */
    {
        return tree;
    }
}
