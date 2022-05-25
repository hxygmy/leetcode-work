struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 1. 快慢指针，快指针比慢指针快一步（是一步速度差这么说，但还是慢1快2快速得到答案，别整活）
// 这个太简单了，想不 AC，想写出 bug 都困难
// 记得这道题有升阶版本，但今天好像刷的有十多道了，
// 计划中还差一道 hard 没做，先不管这个题的升阶了
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
            return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            if (slow == fast)
            {
                return true;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};