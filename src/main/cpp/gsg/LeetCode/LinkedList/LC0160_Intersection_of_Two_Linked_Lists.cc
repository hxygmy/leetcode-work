struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 3. 反而忘了最朴素的 set 判重方法，这里留一句话记着

// 2. 双指针分别遍历双链表（艺术）
// 被 clangformatter 改了缩进，没那么艺术了，不如再多加点换行清晰一点
// 就这样吗，要看这个代码不如去再写一遍爽一爽
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while (p1 || p2)
        {
            if (p1 == p2)
                return p1;
            if (nullptr == p1)
                p1 = headB;
            else
                p1 = p1->next;
            if (nullptr == p2)
                p2 = headA;
            else
                p2 = p2->next;
        }
        return p1;
    }
};

// 1. 双指针分别遍历两个链表（又臭又长版本，思路还算清晰，放在这里当反例）
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA && pB)
        {
            if (pA == pB)
                return pA;
            pA = pA->next;
            pB = pB->next;
        }

        // 两者同时为空，都到头了，说明不相交
        if (!pA && !pB)
            return nullptr;

        int diff = 0;
        if (pA)
        {
            while (pA)
            {
                pA = pA->next;
                ++diff;
            }
            pA = headB;
            pB = headA;
            while (diff--)
                pB = pB->next;
            while (pA && pB)
            {
                if (pA == pB)
                    return pA;
                pA = pA->next;
                pB = pB->next;
            }
        }
        else
        {
            while (pB)
            {
                pB = pB->next;
                ++diff;
            }
            pA = headB;
            pB = headA;
            while (diff--)
                pA = pA->next;
            while (pA && pB)
            {
                if (pA == pB)
                    return pA;
                pA = pA->next;
                pB = pB->next;
            }
        }

        return nullptr;
    }
};