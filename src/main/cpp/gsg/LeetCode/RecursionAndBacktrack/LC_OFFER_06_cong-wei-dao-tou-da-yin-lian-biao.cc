#include <vector>
#include <stack>

using std::stack;
using std::vector;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 2. 递归解法
class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> memo;
        reverseStore(head, memo);
        return memo;
    }

private:
    void reverseStore(ListNode *p, vector<int> &memo)
    {
        if (p == nullptr)
            return;
        reverseStore(p->next, memo);
        memo.push_back(p->val);
    }
};

// 1. 保底解法 栈 （下次再见解法）
class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        ListNode *p = head;
        stack<int> memo;
        while (p)
        {
            memo.push(p->val);
            p = p->next;
        }
        vector<int> res;
        while (!memo.empty())
        {
            res.push_back(memo.top());
            memo.pop();
        }
        return res;
    }
};