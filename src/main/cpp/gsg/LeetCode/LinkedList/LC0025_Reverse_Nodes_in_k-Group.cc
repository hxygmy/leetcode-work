struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1. hard 让我清醒，今天刷了几道 medium 和 easy 的链表题，觉得太简单了，就一点笔记啥的都没做，
// 也没放到这个 project 里面，想起计划昨天还是前天要做的这个 hard 搁置了，就来做一下，
// 感觉递归没意思，就纯手动挡手撸，于是一不小心就写出了一堆bug，这道题得历时一小时，
// 也是自己第一次纯手撸的 hard，一次提交通过，纪念一下，直接提交时45%，稍微改了两句近90%，
// 今天这道题体力消耗过大了，先不优化这段代码了。
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (1 == k)
            return head;
        int count = 1;
        ListNode *preOfSet = nullptr;
        ListNode *firstOfSet = head;
        ListNode *p = head; // endOfSet;
        ListNode *newHead = nullptr;
        bool haveGotNewHead = false;
        while (p)
        {
            if (count == k)
            { // 到达指定数目则进行翻转，重置计数，维护指针
                // 获取新的头指针（整个链表的）
                if (!haveGotNewHead)
                {
                    newHead = p; // 要翻转的最后一个节点，即新的头结点
                    haveGotNewHead = true;
                }

                // 翻转所需要的指针
                ListNode *cur = firstOfSet;
                ListNode *pre = preOfSet;
                ListNode *lastTail = pre;

                // 维护计数和指针
                count = 1;
                p = p->next;
                preOfSet = firstOfSet; // new end of cur set
                firstOfSet = p;        // begin of next set

                // 进行翻转
                while (cur != firstOfSet)
                {
                    ListNode *tmp = cur->next;
                    cur->next = pre;
                    pre = cur;
                    cur = tmp;
                }
                if (lastTail)
                    lastTail->next = pre;
            }
            else
            {
                ++count;
                p = p->next;
            }
        }
        preOfSet->next = firstOfSet;

        return newHead;
    }
};