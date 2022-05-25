struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 2. 只遍历一次，最笨的方法是 vector完整记录，
// 好一点是 队列 存 k 的节点，过于简单，不记录代码了

// 1. 快慢指针，过于经典，不再赘述
class Solution
{
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
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
        return slow;
    }
};