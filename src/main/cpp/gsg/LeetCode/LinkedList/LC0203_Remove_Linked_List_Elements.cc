/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1. 自己写的最好版本，暂未学习他人解法
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (nullptr == head)
            return nullptr;
        while (head && val == head->val)
        {
            head = head->next;
        }

        ListNode *p = head;
        while (p && p->next)
        {
            if (val == p->next->val)
            {
                p->next = p->next->next;
            }
            else
            {
                p = p->next;
            }
        }

        return head;
    }
};