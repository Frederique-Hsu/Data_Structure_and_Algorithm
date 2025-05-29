/*!
 *  \file       bvh_tree.cpp
 *  \brief      Implement the BVH tree algorithm.
 *  
 */


#include "bvh_tree.hpp"

BVH::BVH()
{
}

BVH::~BVH()
{
}

bool BVH::isLeaf(const NodePtr pnode) const
{
    (void)pnode;
    /*!
     *  \todo   insert code here in the future to implement this method.
     */
    return bool{};
}

NodePtr BVH::getLeftChild(const NodePtr parentNode) const
{
    (void)parentNode;
    /*!
     *  \todo   insert code here in the future.
     */
    return NodePtr{};
}

NodePtr BVH::getRightChild(const NodePtr parentNode) const
{
    (void)parentNode;

    return NodePtr{};
}

AABB BVH::getAABB(const NodePtr pnode) const
{
    (void)pnode;

    return AABB{};
}

int BVH::getObjectIdx(const NodePtr node) const
{
    (void)node;

    return int{};
}

void traverseRecursive(CollisionList&   list,
                       const BVH&       bvh,
                       const AABB&      queryAABB,
                       int              queryObjectIdx,
                       NodePtr          node)
{
    // Bounding box overlaps with the queryAABB
    if (checkOverlap(bvh.getAABB(node), queryAABB))
    {
        if (bvh.isLeaf(node))
        {
            list.add(queryObjectIdx, bvh.getObjectIdx(node));
        }
        else
        {
            NodePtr childL = bvh.getLeftChild(node);
            NodePtr childR = bvh.getRightChild(node);
            traverseRecursive(list, bvh, queryAABB, queryObjectIdx, childL);
            traverseRecursive(list, bvh, queryAABB, queryObjectIdx, childR);
        }
    }
}

bool checkOverlap(const AABB& boundingBox1, const AABB& boundingBox2)
{
    (void)boundingBox1;
    (void)boundingBox2;

    return bool{};
}

CollisionList::CollisionList()
{
}

CollisionList::~CollisionList()
{
}

void CollisionList::add(int request_obj_idx, int ack_obj_idx)
{
    (void)request_obj_idx;
    (void)ack_obj_idx;
}

Node* generateTopDownHierarchy(unsigned int*    sorted_morton_codes,
                               int*             sorted_object_ids,
                               int              first,
                               int              last)
{
    if (first == last)
    {   // 如果当前需要考虑的范围只包含一个对象，那么就直接生成一个叶子节点
        return new LeafNode(&sorted_object_ids[first]);
    }
    // 在[first, last]范围内部选择一个对象，将该范围划分成左右两部分
    int split = findSplit(sorted_morton_codes, first, last);

    // 递归地处理当前节点的左子树、右子树
    Node* left_child = generateTopDownHierarchy(sorted_morton_codes, sorted_object_ids, first, split);
    Node* right_child = generateTopDownHierarchy(sorted_morton_codes, sorted_object_ids, split + 1, last);
    
    return new InternalNode(left_child, right_child);
}

int findSplit(unsigned int* sorted_morton_codes, int first, int last)
{
    unsigned int first_code = sorted_morton_codes[first];
    unsigned int last_code = sorted_morton_codes[last];

    if (first_code == last_code)
    {
        return (first + last) / 2;
    }
}