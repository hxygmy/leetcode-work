// 二维数组解法说是最简单直接的思路
// 但我还真没写过
// 吃了学习前没有暴力解决过的亏。。。
// 但省时间了，先不搞这个

#include <vector>
#include <queue>

using std::queue;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 1. 辅助队列（二维数组解法我还真就没写过，没有清晰确定的思路。。。）
class Solution
{
public:
    vector<int> levelOrder(TreeNode *root)
    {
        vector<int> res;
        queue<TreeNode *> que;
        if (root != nullptr)
        {
            que.emplace(root);
        }
        while (!que.empty())
        {
            res.emplace_back(que.front()->val);
            if (que.front()->left)
            {
                que.emplace(que.front()->left);
            }
            if (que.front()->right)
            {
                que.emplace(que.front()->right);
            }
            que.pop();
        }

        return res;
    }
};