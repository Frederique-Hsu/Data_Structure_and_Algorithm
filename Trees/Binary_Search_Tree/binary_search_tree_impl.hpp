/*!
 *  \file   binary_search_tree_impl.hpp
 *  \brief  Implement the class BinarySearchTree
 *
 */

/*! Implementation for \struct BinaryNode */
template<typename Comparable>
BinarySearchTree<Comparable>::BinaryNode::BinaryNode(const Comparable& elem,
                                                     BinarySearchTree<Comparable>::BinaryNode *lt,
                                                     BinarySearchTree<Comparable>::BinaryNode *rt)
    : element(elem), left(lt), right(rt)
{
}

template<typename Comparable>
BinarySearchTree<Comparable>::BinaryNode::BinaryNode(Comparable&& elem,
                                                     BinarySearchTree<Comparable>::BinaryNode *lt,
                                                     BinarySearchTree<Comparable>::BinaryNode *rt)
    : element(std::move(elem)), left(lt), right(rt)
{
}

template<typename Object, typename Comparator>
BSTree<Object, Comparator>::BinaryNode::BinaryNode(const Object& elem, 
                                                   BSTree<Object, Comparator>::BinaryNode *lt,
                                                   BSTree<Object, Comparator>::BinaryNode *rt)
    : element(elem), left(lt), right(rt)
{
}

template<typename Object, typename Comparator>
BSTree<Object, Comparator>::BinaryNode::BinaryNode(Object&& elem, 
                                                   BSTree<Object, Comparator>::BinaryNode *lt,
                                                   BSTree<Object, Comparator>::BinaryNode *rt)
    : element(std::move(elem)), left(lt), right(rt)
{
}

/*============================================================================*/
/*! Implementation for \class BSTree */
template<typename Object, typename Comparator>
BSTree<Object, Comparator>::BSTree::BSTree(const Object& root_element) : root(nullptr)
{
    root = new BSTree<Object, Comparator>::BinaryNode(root_element, nullptr, nullptr);
}

template<typename Object, typename Comparator>
BSTree<Object, Comparator>::~BSTree()
{
    if (root)
        delete root;
}

/*============================================================================*/
/*! Implementation for \class BinarySearchTree */
template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree() : root(nullptr)
{
}

template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const Comparable& root_element)
    : root(new BinarySearchTree<Comparable>::BinaryNode(root_element, nullptr, nullptr))
{
}

template<typename Comparable> BinarySearchTree<Comparable>::~BinarySearchTree()
{
    if (root)
        delete root;
}

/*!
 *  \brief      Return true if obj is found in the tree.
 *  \param[in]  obj - the object you want to find
 *  \return     true if found, false otherwise
 */
template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& obj) const
{
    return contains(obj, root);
}

/*!
 *  \brief      Internal method to test whether an item is in a subtree
 *  \param[in]  obj is the item to search for.
 *  \param[in]  tree_root_node is the node that roots the subtree
 *  \return     True if found, false otherwise
 */
template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& obj,
                                            BinarySearchTree<Comparable>::BinaryNode* tree_root_node) const
{
    if (tree_root_node == nullptr)
        return false;
    else if (obj < tree_root_node->element)
        return contains(obj, tree_root_node->left);
    else if (tree_root_node->element < obj)             /*! \note uniformly utilize < operator */
        return contains(obj, tree_root_node->right);
    else    // obj == tree_root_node->element
        return true;
}

template<typename Object, typename Comparator>
bool BSTree<Object, Comparator>::contains(const Object& obj,
                                          BSTree<Object, Comparator>::BinaryNode *tree_root_node) const
{
    if (tree_root_node == nullptr)
        return false;
    else if (isLessThan(obj, tree_root_node->element))
        return contains(obj, tree_root_node->left);
    else if (isLessThan(tree_root_node->element, obj))
        return contains(obj, tree_root_node->right);
    else
        return true;
}

/*!
 *  \brief      Insert \a obj into the tree; duplicates are ignored.
 *  \param[in]  obj - the object you want to insert
 *  \return     None
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& obj)
{
    insert(obj, root);
}

/*!
 *  \brief      Remove \a obj from the tree. Nothing is done if \a obj is not found.
 *  \param[in]  obj - the very \a obj you want to remove from the tree.
 *  \return     None
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& obj)
{
    remove(obj, root);
}
