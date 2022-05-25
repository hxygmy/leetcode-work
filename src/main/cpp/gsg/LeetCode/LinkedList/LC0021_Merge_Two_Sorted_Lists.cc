#include <stdlib.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1. 逃了 递归 课，申请一个哨兵节点
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = (ListNode *)calloc(1, sizeof(ListNode));
        ListNode *p = dummy;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                p->next = list1;
                list1 = list1->next;
            }
            else
            {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }

        // 至多有一个非空
        if (list1)
        {
            p->next = list1;
        }
        else
        {
            p->next = list2;
        }

        return dummy->next;
    }
};