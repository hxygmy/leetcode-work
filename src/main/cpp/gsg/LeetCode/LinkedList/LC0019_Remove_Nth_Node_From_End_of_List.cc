#include <queue>

using std::queue;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 2. 题中说明的进阶解：只扫描一次（看了下别人写的都认为是双指针已经算是只扫描一次了，。，。，，。。）
// 我这个是真的只扫描一次，每个节点只扫描一次，。这个想当然是没双指针快
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p = head;
        queue<ListNode *> memoQue;
        // 队列存储 n + 1 个结点，便于删除
        // 如果队列只存储了 n 个结点，说明要删除的是头结点
        while (p)
        {
            if (memoQue.size() > n) // memoQue.size() == n+1
            {
                memoQue.pop();
            }
            memoQue.push(p);
            p = p->next;
        }
        if (memoQue.size() == n)
        {
            return head->next;
        }
        memoQue.front()->next = memoQue.front()->next->next;
        return head;
    }
};

// 1.快慢指针找到倒数第N个结点，用prev记录慢指针的前一个结点便于删除
// 这里未进行 题中的进阶解————只扫描一次，
// 因为那是我第一次做 倒数第k个结点 自然想到的第一种解法，
// 现在去写进阶解
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 先用快慢指针找到倒数第 n 个结点
        ListNode *slow = head;
        ListNode *prev = nullptr;
        ListNode *fast = head;
        while (n--)
        {
            fast = fast->next;
        }
        while (fast)
        {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        // 要删除 头 结点
        if (nullptr == prev)
        {
            return slow->next;
        }
        // 删除 尾 结点 或 中间结点
        prev->next = slow->next;
        return head;
    }
};