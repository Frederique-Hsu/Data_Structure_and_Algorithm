/*!
 *  \file       bvh_tree.cu
 *  \brief      
 *  
 */


#include "bvh_tree.cuh"


__global__ void findPotentialCollisions(CollisionList   list,
                                        BVH             bvh,
                                        AABB*           objectAABBs,
                                        int             numObjects)
{
    int idx = threadIdx.x + blockDim.x * blockIdx.x;
    if (idx < numObjects)
    {
        traverseRecursive(list, bvh, objectAABBs[idx], idx, bvh.getRoot());
    }
}

__device__ void traverseIterative(CollisionList&    list,
                                  BVH&              bvh,
                                  AABB&             queryAABB,
                                  int               queryObjectIdx)
{
    /*  Allocate traversal stack from thread-local memory, and push nullptr
     *  to indicate that there are no postponed nodes.
     */
    NodePtr stack[6];
    NodePtr* stackPtr = stack;
    *stackPtr++ = nullptr;  // push stack

    // Traverse nodes starting from the root.
    NodePtr node = bvh.getRoot();
    do
    {
        // Check each child node for overlap
        NodePtr left_child = bvh.getLeftChild(node);
        NodePtr right_child = bvh.getRightChild(node);
        bool left_overlap = checkOverlap(queryAABB, bvh.getAABB(left_child));
        bool right_overlap = checkOverlap(queryAABB, bvh.getAABB(right_child));

        // Query whether to overlap with a leaf node, in order to report collision.
        if (left_overlap && bvh.isLeaf(left_child))
        {
            list.add(queryObjectIdx, bvh.getObjectIdx(left_child));
        }
        if (right_overlap && bvh.isLeaf(right_child))
        {
            list.add(queryObjectIdx, bvh.getObjectIdx(right_child));
        }

        // Query whether to overlap with an internal node, then traverse recursively
        bool left_traverse = (left_overlap && !bvh.isLeaf(left_child));
        bool right_traverse = (right_overlap && !bvh.isLeaf(right_child));
        if (!left_traverse and !right_overlap)
        {
            node = *--stackPtr;     // pop stack
        }
        else
        {
            node = left_traverse ? left_child : right_child;
            if (left_traverse && right_traverse)
            {
                *stackPtr++ = right_child;  // push stack
            }
        }
    }
    while (node != nullptr);
}

__global__ void findPotentialCollisions(CollisionList   list,
                                        BVH             bvh)
{
    int idx = threadIdx.x + blockDim.x * blockIdx.x;
    if (idx < bvh.getNumLeaves())
    {
        NodePtr leaf = bvh.getLeaf(idx);
        AABB leaf_aabb = bvh.getAABB(leaf);
        traverseIterative(list, bvh, leaf_aabb, bvh.getObjectIdx(leaf));
    }
}