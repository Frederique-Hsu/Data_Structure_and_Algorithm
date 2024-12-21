/*!
 *  \file       merge_k_sorted_lists.cpp
 *  \brief      
 *  
 */


#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) 
    {
        if (lists.size() == 0)
        {
            return nullptr;
        }
        std::vector<int> numbers;

        for (ListNode* single_list : lists)
        {
            ListNode* pnode = single_list;
            while (pnode != nullptr)
            {
                int number = pnode->val;
                numbers.push_back(number);

                pnode = pnode->next;
            }
        }   

        std::sort(numbers.begin(), numbers.end()); 
        return buildListNodeFrom(numbers);
    }
public:
    ListNode* buildListNodeFrom(const std::vector<int>& vec)
    {
        if (vec.size() == 0)
        {
            return nullptr;
        }
        ListNode* list = new ListNode(vec[0]);
        ListNode* pnode = list;
        for (auto index = 1U; index < vec.size(); ++index)
        {
            pnode->next = new ListNode(vec[index]);
            pnode = pnode->next;
        }
        return list;
    }

    void destroyListNode(ListNode* list)
    {
        ListNode* pnode = list;
        while (pnode != nullptr)
        {
            ListNode* next_node = pnode->next;
            delete pnode;
            pnode = next_node;
        }
    }
};

TEST(UTest, CheckmergeKLists)
{
    ListNode* list1 = Solution().buildListNodeFrom(std::vector<int>{1, 4, 5});
    ListNode* list2 = Solution().buildListNodeFrom(std::vector<int>{1, 3, 4});
    ListNode* list3 = Solution().buildListNodeFrom(std::vector<int>{2, 6});

    std::vector<ListNode*> lists{list1, list2, list3};

    ListNode* result = Solution().mergeKLists(lists);
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode *pnode1 = l1, *pnode2 = l2;

    ListNode* result = new ListNode();
    ListNode* pnode = result;

    int quotient = 0;
    while (pnode1 != nullptr || pnode2 != nullptr)
    {
        int num1 = (pnode1 == nullptr) ? 0 : (pnode1->val);
        int num2 = (pnode2 == nullptr) ? 0 : (pnode2->val);

        int total = num1 + num2 + quotient;
        int remainder = total % 10;
        quotient = total / 10;

        pnode->val = remainder;
        pnode->next = new ListNode();
        pnode = pnode->next;

        pnode1 = (pnode1 == nullptr) ? nullptr : pnode1->next;
        pnode2 = (pnode2 == nullptr) ? nullptr : pnode2->next;
    }
    if (quotient != 0)
    {
        pnode->val = quotient;
    }
    auto removeLastRedundantNode = [](ListNode* list)
    {
        ListNode* pnode = list;
        while (pnode->next->next != nullptr)
        {
            pnode = pnode->next;
        }
        ListNode* tail_node = pnode;
        if (tail_node->next->val == 0)
        {
            delete tail_node->next;     // remove the last redundant node;
            tail_node->next = nullptr;
        }
    };
    removeLastRedundantNode(result);
    return result;
}



TEST(UTest, CHeckaddTwoNumbers)
{
    ListNode* list1 = Solution().buildListNodeFrom(std::vector<int>{9, 9, 9, 9, 9, 9, 9});
    ListNode* list2 = Solution().buildListNodeFrom(std::vector<int>{9, 9, 9, 9});

    ListNode* result = addTwoNumbers(list1, list2);
}