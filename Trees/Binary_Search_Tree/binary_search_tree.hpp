/*!
 *  \file binary_search_tree.hpp
 *  \brief  Define the data structure of Binary Search Tree
 *
 */

#pragma once

#include <utility>
#include <functional>
#include <iostream>

template<typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree();
    explicit BinarySearchTree(const Comparable& root_element);
    BinarySearchTree(const BinarySearchTree& rhs);
    BinarySearchTree(BinarySearchTree&& rhs);
    ~BinarySearchTree();
    BinarySearchTree& operator=(const BinarySearchTree& rhs);
    BinarySearchTree& operator=(BinarySearchTree&& rhs);
private:
    struct BinaryNode
    {
        Comparable  element;
        BinaryNode  *left;
        BinaryNode  *right;

        BinaryNode(const Comparable& elem, BinaryNode *lt, BinaryNode *rt);
        BinaryNode(Comparable&& elem, BinaryNode *lt, BinaryNode *rt);
    };

    BinaryNode *root;
private:
    void insert(const Comparable& obj, BinaryNode*& tree_root_node);
    void insert(Comparable&& obj, BinaryNode*& tree_root_node);
    void remove(const Comparable& obj, BinaryNode*& tree_root_node);
    BinaryNode* findMin(BinaryNode* tree_root_node) const;
    BinaryNode* findMax(BinaryNode* tree_root_node) const;
    bool contains(const Comparable& obj, BinaryNode* tree_root_node) const;
    void makeEmpty(BinaryNode*& tree_root_node);
    void printTree(BinaryNode* node, std::ostream& out) const;
    BinaryNode* clone(BinaryNode* tree_root_node) const;
public:
    const Comparable& findMin() const;
    const Comparable& findMax() const;
    bool contains(const Comparable& obj) const;
    bool isEmpty() const;
    void printTree(std::ostream& out = std::cout) const;

    void makeEmpty();
    void insert(const Comparable& obj);
    void insert(Comparable&& obj);
    void remove(const Comparable& obj);

    void preorderTraverse();
    void postorderTraverse();
    void inorderTraverse();
};

template<typename Object, typename Comparator=std::less<Object>>
class BSTree
{
public:
    explicit BSTree(const Object& root_element);
    ~BSTree();
private:
    struct BinaryNode
    {
        Object      element;
        BinaryNode  *left;
        BinaryNode  *right;

        BinaryNode(const Object& elem, BinaryNode *lt, BinaryNode *rt);
        BinaryNode(Object&& elem, BinaryNode *lt, BinaryNode *rt);
    };

    BinaryNode *root;
    Comparator isLessThan;
private:
    bool contains(const Object& obj, BinaryNode *tree_root_node) const;
};


#include "binary_search_tree_impl.hpp"
