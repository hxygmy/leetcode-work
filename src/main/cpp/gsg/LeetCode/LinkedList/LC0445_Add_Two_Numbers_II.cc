struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1. workable，用了 dummy，先处理尾结点，构建堆空间新链表 等一系列手段降低编程复杂度
// 但还是写出了一坨 shit
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p1 = reverseLinkedList(l1);
        ListNode *p2 = reverseLinkedList(l2);
        ListNode *dummy = new ListNode(0);
        // 先整个尾结点，之后判断之后数是否要进位就不用判空了
        ListNode *tail = new ListNode(0);
        dummy->next = tail;
        tail->val = p1->val + p2->val;
        p1 = p1->next;
        p2 = p2->next;

        while (p1 && p2)
        {
            ListNode *newNode = new ListNode(0);
            newNode->next = dummy->next;
            dummy->next = newNode;
            newNode->val = p1->val + p2->val;
            if (newNode->next->val >= 10)
            {
                newNode->next->val -= 10;
                newNode->val += 1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode *remain = p1 ? p1 : p2;
        while (remain)
        {
            ListNode *newNode = new ListNode(0);
            newNode->next = dummy->next;
            dummy->next = newNode;
            newNode->val = remain->val;
            if (newNode->next->val >= 10)
            {
                newNode->next->val -= 10;
                newNode->val += 1;
            }
            remain = remain->next;
        }

        if (dummy->next->val >= 10)
        {
            dummy->next->val -= 10;
            dummy->val = 1;
            return dummy;
        }
        return dummy->next;
    }

    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};