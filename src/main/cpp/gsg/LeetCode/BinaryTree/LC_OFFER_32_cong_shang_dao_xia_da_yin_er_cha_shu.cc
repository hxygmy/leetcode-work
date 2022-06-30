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
// 比上个版本写的好看多了
// 经常访问队首就把队首取出来嘛
// 看起来好看多了
class Solution
{
public:
    vector<int> levelOrder(TreeNode *root)
    {
        vector<int> res;
        queue<TreeNode *> que;
        if (root)
            que.emplace(root);

        while (!que.empty())
        {
            TreeNode *head = que.front();
            res.emplace_back(head->val);
            if (head->left)
                que.emplace(head->left);
            if (head->right)
                que.emplace(head->right);
            que.pop();
        }

        return res;
    }
};