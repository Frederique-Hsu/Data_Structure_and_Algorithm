/*!
 *  \file       bvh_tree.cuh
 *  \brief      
 *  
 */


#ifndef BVH_TREE_CUH
#define BVH_TREE_CUH

    class BVH;
    struct AABB;
    class Node;

    using NodePtr = Node*;

    class CollisionList
    {
    public:
        CollisionList();
        ~CollisionList();
    public:
        void add(int request_obj_idx, int ack_obj_idx);
    };

    class BVH
    {
    public:
        BVH();
        ~BVH();
    public:
        NodePtr getRoot();
        NodePtr getLeftChild(const NodePtr parent_node);
        NodePtr getRightChild(const NodePtr parent_node);
        AABB getAABB(const NodePtr node);
        bool isLeaf(const NodePtr node);
        int getObjectIdx(const NodePtr node);
        int getNumLeaves();
        NodePtr getLeaf(int object_idx);

        NodePtr getRightmostLeafInLeftSubtree(const NodePtr node);
        NodePtr getRightmostLeafInRightSubtree(const NodePtr node);
    };

    struct AABB
    {
    };

    class Node
    {
    };

    __device__ void traverseRecursive(CollisionList& list,
                                      const BVH& bvh,
                                      const AABB& queryAABB,
                                      int queryObjectIdx,
                                      NodePtr node);

    __device__ void traverseIterative(CollisionList& list,
                                      BVH& bvh,
                                      AABB& queryAABB,
                                      int queryObjectIdx);
    
    __device__ void traverseIterative(CollisionList& list,
                                      BVH& bvh,
                                      AABB& queryAABB,
                                      int queryObjectIdx,
                                      NodePtr queryLeaf);

    __global__ void findPotentialCollisions(CollisionList list,
                                            BVH bvh,
                                            AABB* objectAABB,
                                            int numObjects);

    __global__ void findPotentialCollisions(CollisionList list,
                                            BVH bvh);
    
    __global__ bool checkOverlap(const AABB& box1, const AABB& box2);

#endif  /* BVH_TREE_CUH */