struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 2. 只遍历一次，队列，重复水题

// 1. 快慢指针，重复水题
class Solution
{
public:
    int kthToLast(ListNode *head, int k)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (k--)
        {
            fast = fast->next;
        }
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->val;
    }
};