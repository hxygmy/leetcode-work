struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 2. 我的递归解，比起官解都有极大的差距，但自己写的自己容易理解
// 日后再提升吧
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        ListNode *p1 = l1, *p2 = l2;
        merge(tail, p1, p2);
        return dummy->next;
    }

    void merge(ListNode *tail, ListNode *p1, ListNode *p2)
    {
        if (p1 == nullptr || p2 == nullptr)
        {
            tail->next = p1 ? p1 : p2;
            return;
        }
        if (p1->val <= p2->val)
        {
            tail->next = p1;
            merge(p1, p1->next, p2);
        }
        else
        {
            tail->next = p2;
            merge(p2, p1, p2->next);
        }
    }
};

// 1. 普通解法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        ListNode *p1 = l1, *p2 = l2;
        while (p1 && p2)
        {
            if (p1->val <= p2->val) tail->next = p1, tail = p1, p1 = p1->next;
            else    tail->next = p2, tail = p2, p2 = p2->next;
        }
        tail->next = p1 ? p1 : p2;
        return dummy->next;
    }
};