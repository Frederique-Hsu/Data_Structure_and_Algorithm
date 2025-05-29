/*!
描述
假设链表中每一个节点的值都在 0 - 9 之间，那么链表整体就可以代表一个整数。
给定两个这种链表，请生成代表两个整数相加值的结果链表。
数据范围：0≤n,m≤10000000≤n,m≤1000000，链表任意值 0≤val≤90≤val≤9
要求：空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)

例如：链表 1 为 9->3->7，链表 2 为 6->3，最后生成新的结果链表为 1->0->0->0。 
 */


#include <stack>

class Solution 
{
public:
    struct ListNode
    {
        int val;
        struct ListNode* next;
        ListNode(int x) : val{x}, next{nullptr} {}
    };
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) 
    {
        std::stack<int> stack1, stack2;

        ListNode* node1 = head1;
        while (node1 != nullptr)
        {
            int value = node1->val;
            stack1.push(value);

            node1 = node1->next;
        }

        ListNode* node2 = head2;
        while (node2 != nullptr)
        {
            int value = node2->val;
            stack2.push(value);

            node2 = node2->next;
        }

        std::stack<int> result;

        int carry = 0;
        while (!stack1.empty() || !stack2.empty())
        {
            int value1 = (stack1.empty() == true) ? 0 : stack1.top();
            int value2 = (stack2.empty() == true) ? 0 : stack2.top();
            
            int sum = (carry + value1 + value2) % 10;
            carry = (value1 + value2) / 10;

            result.push(sum);

            stack1.pop();
            stack2.pop();
        }

        ListNode* result_list = new ListNode(0);
        ListNode* pnode = result_list;
        while (!result.empty())
        {
            pnode->val = result.top();

            result.pop();
            if (result.empty() != false)
            {
                pnode->next = new ListNode(0);
                pnode = pnode->next;
            }
            else
            {
                pnode->next = nullptr;
            }
        }

        return result_list;
    }
};
