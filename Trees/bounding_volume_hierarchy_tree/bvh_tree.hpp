/*!
 *  \file       bvh_tree.hpp
 *  \brief      bounding volume hoerarchy tree
 *  \details    
 *  
 */


#pragma once


#include <list>

class BVH;      // bounding volume hierarchy
class AABB;     // axis-aligned bounding box
class CollisionList;
class Node;
class LeafNode;
class InternalNode;

using NodePtr = Node*;

void traverseRecursive(CollisionList&   list,
                       const BVH&       bvh,
                       const AABB&      queryAABB,
                       int              queryObjectIdx,
                       NodePtr          node);

bool checkOverlap(const AABB& boundingBox1, const AABB& boundingBox2);

class BVH
{
public:
    explicit BVH();
    ~BVH();
public:
    bool isLeaf(const NodePtr pnode) const;
    NodePtr getLeftChild(const NodePtr parentNode) const;
    NodePtr getRightChild(const NodePtr parentNode) const;
    AABB getAABB(const NodePtr pnode) const;
    int getObjectIdx(const NodePtr node) const;
};

class AABB
{
};

class Node
{
};

class CollisionList
{
public:
    CollisionList();
    ~CollisionList();
public:
    void add(int request_obj_idx, int ack_obj_idx);
};

Node* generateTopDownHierarchy(unsigned int* sorted_morton_codes,   // the Morton-Code array which have been already sorted.
                               int* sorted_object_ids,
                               int first,
                               int last);

int findSplit(unsigned int* sorted_morton_codes, int first, int last);

class LeafNode : public Node
{
public:
    LeafNode(int* corresponding_object_id);
    ~LeafNode();
private:
    int* object_id;
};

class InternalNode : public Node
{
public:
    InternalNode(Node* left_child, Node* right_child);
    ~InternalNode();
private:
    Node* m_left_subnode;
    Node* m_right_subnode;
};