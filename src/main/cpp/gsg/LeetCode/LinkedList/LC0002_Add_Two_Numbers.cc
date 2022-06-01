struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 3. 原地操作，只申请一个 dummy 和 末尾进位必须申请的 tail原地操作
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *p1 = l1; // p1 当基
        ListNode *p2 = l2;
        // 设两个链表均不为空
        ListNode *tail = p1; // 不多这一个指针，多一个指针更好写，更好读
        dummy->next = tail;
        tail->val = p1->val + p2->val;
        p1 = p1->next;
        p2 = p2->next;

        while (p1 && p2)
        {
            if (tail->val >= 10)
            {
                tail->val -= 10;
                p1->val += 1;
            }
            p1->val += p2->val;
            tail->next = p1;
            tail = p1;
            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode *remain = p1 ? p1 : p2;
        while (remain)
        {
            if (tail->val >= 10)
            {
                tail->val -= 10;
                remain->val += 1;
            }
            tail->next = remain;
            tail = remain;
            remain = remain->next;
        }
        if (tail->val >= 10)
        {
            tail->val -= 10;
            ListNode *newNode = new ListNode(0);
            newNode->val = 1;
            tail->next = newNode;
            tail = newNode;
        }

        return dummy->next;
    }
};

// 2. 修改自下面的自作聪明构造 顺序链表 的解，
//    写的比较丑，但也90%，暂时没心情整理了，先搁这吧，
//    没想到能在这出岔子
//    这里不应该再申请这么多新节点空间的，按题目要求很好写，见下一个解（数字上升）
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        while (l1 && l2)
        {
            ListNode *newNode = new ListNode(0);
            newNode->val = l1->val + l2->val;
            tail->next = newNode;
            if (tail && tail->val >= 10)
            {
                tail->val -= 10;
                newNode->val += 1;
            }
            tail = newNode;
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *remain = l1 ? l1 : l2;
        while (remain)
        {
            ListNode *newNode = new ListNode(0);
            newNode->val = remain->val;
            tail->next = newNode;
            if (tail && tail->val >= 10)
            {
                tail->val -= 10;
                newNode->val += 1;
            }
            tail = newNode;
            remain = remain->next;
        }

        if (tail->val >= 10)
        {
            ListNode *newNode = new ListNode(0);
            tail->val -= 10;
            newNode->val = 1;
            tail->next = newNode;
            tail = newNode;
        }

        return dummy->next;
    }
};

// 1. 自作聪明的错误解
// 返回了正常形式的答案。，，，，。。，
// C++ 刷题 用 new，不要用 malloc 系列

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// C++ 中 不要使用 malloc/calloc ……，
// 刷题自己不处理内存泄漏问题，
// LeetCode 就会帮你干掉，目前看来一个节点没有问题，
// 多了可能会给你 delete，但是申请的时候是 malloc 系
// 就会寄
// 习惯性地把答案写成了正常形式。。。。。。。。
// 自作聪明，。，。，
// 保留 自作聪明 解
// inline ListNode* getNewNode(void)
// {
// return (ListNode*)calloc(1, sizeof(ListNode));
// }

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // ListNode *dummy = getNewNode();
        ListNode *dummy = new ListNode(0);
        while (l1 && l2)
        {
            ListNode *newNode = new ListNode(0);
            newNode->val = l1->val + l2->val;
            newNode->next = dummy->next;
            dummy->next = newNode;
            if (newNode->next && newNode->next->val >= 10)
            {
                newNode->next->val -= 10;
                newNode->val += 1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *remain = l1 ? l1 : l2;
        while (remain)
        {
            ListNode *newNode = new ListNode(0);
            newNode->val = remain->val;
            newNode->next = dummy->next;
            dummy->next = newNode;
            if (newNode->next && newNode->next->val >= 10)
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
        }

        return dummy->val ? dummy : dummy->next;
    }
};