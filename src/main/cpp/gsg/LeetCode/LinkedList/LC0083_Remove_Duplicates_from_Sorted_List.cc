struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1. 基本操作，带着刚做的203的惯性，第一遍想得太多，写得很蠢，
//    当前已经修正为正常版本
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *p = head;
        while (p && p->next)
        {
            if (p->val == p->next->val)
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