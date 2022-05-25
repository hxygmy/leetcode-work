struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1. 出乎意料的十分顺畅地 AC 了，并没有找到有趣的规律，直接顺着写完了
// 下周再找规律整理，精简代码行数
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        // ListNode *odd = new ListNode(0);
        // ListNode *even = new ListNode(0);
        ListNode *tailOdd = head;
        ListNode *headEven = head->next;
        ListNode *tailEven = headEven;
        ListNode *p = tailEven->next;
        bool nextIsOdd = 1;
        while (p)
        {
            ListNode *tmp = p->next;
            if (nextIsOdd)
            {
                tailOdd->next = p;
                tailOdd = p;
                nextIsOdd = false;
            }
            else
            {
                tailEven->next = p;
                tailEven = p;
                nextIsOdd = true;
            }
            p = tmp;
        }
        tailEven->next = nullptr;
        tailOdd->next = headEven;
        return head;
    }
};