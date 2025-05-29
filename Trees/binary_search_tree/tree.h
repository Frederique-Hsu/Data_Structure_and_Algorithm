/*!
 *  \file       tree.h
 *  \brief      Define the structure of binary search tree.
 *
 */


#ifndef TREE_H
#define TREE_H

#include "element.h"

struct TreeNode;
typedef struct TreeNode     *Position;
typedef struct TreeNode     *SearchTree;

SearchTree MakeEmpty(SearchTree tree);
Position Find(ElementType elem, SearchTree tree);


#endif  /* TREE_H */
