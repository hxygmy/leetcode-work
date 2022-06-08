struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1. 递归解法，貌似写得不太简洁
// 达成进阶目标，至多扫描一次
// 看了一下 labuladong 解，差距貌似有亿点点大。。
// 别人几行就完事了
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        ListNode *pre = nullptr;
        ListNode *catTail = head;
        int count = 1;
        while (count != left)
        {
            pre = catTail; // 用来连接 这是翻转后的头结点
            catTail = catTail->next;
            ++count;
        }
        // count == left, catTail 为要翻转的起点，也是翻转后 连接 未反转的后段的节点

        ListNode *behind = nullptr;
        ListNode *catHead = reverseBT(catTail, count, right, &behind);

        // 反转完要接上
        if (pre)
            pre->next = catHead;
        else
            head = catHead;
        catTail->next = behind;

        return head;
    }

    ListNode *reverseBT(ListNode *begin, int curCount, int end, ListNode **behind)
    { // end == right
        if (curCount == end)
        {
            *behind = begin->next;
            return begin;
        }
        ListNode *newHead = reverseBT(begin->next, curCount + 1, end, behind);
        begin->next->next = begin;
        begin->next = nullptr;
        return newHead;
    }
};