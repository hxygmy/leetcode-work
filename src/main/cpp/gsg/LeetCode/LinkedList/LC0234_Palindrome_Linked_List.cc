#include <vector>

using std::vector;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 2. 快慢指针 找中点 --> 翻转 --> 判断回文
// 做这个题时写出了两个bug(slow跑两步（手滑），tail是prev而不是slow（脑抽，刚写过一边，这就错了）)，
// 偏偏这时候 LeetCode 的调试功能坏了，十分糟心，还是自己太浮躁了，天太热了受不了，耐心看一下代码马上就看出来了
// 。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
// 歇一会，先不做了
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {

        // 1. 快慢指针找到链表的中点
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 2. 从head起跑，fast 为空 则有偶数个非空节点，slow开始刚好有一半节点；
        // fast非空，则有奇数个非空节点，slow刚好在正中央，slow->next为回文检验的起点，slow = slow->next
        if (nullptr != fast)
        {
            slow = slow->next;
        }

        // 3. 从 slow 开始反转链表
        ListNode *prev = nullptr;
        while (slow)
        {
            ListNode *tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }

        // 4. 比较回文串，一头遇空结束比较（原尾开始）（头开始的再遍历一个到空节点，画图比较直观）
        while (prev)
        {
            if (prev->val != head->val)
            {
                return false;
            }
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};

// 1. 纯暴力，但也总比不写强。。。寄
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> memo;
        while (head)
        {
            memo.push_back(head->val);
            head = head->next;
        }
        int left = 0;
        int right = memo.size() - 1;
        while (left < right)
        {
            if (memo[left++] != memo[right--])
            {
                return false;
            }
        }
        return true;
    }
};