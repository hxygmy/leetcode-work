#include <vector>
#include <queue>
#include <utility>

using std::pair;
using std::queue;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 1. 我的理解
// 辅助队列记录pair<节点指针, level>合理的自己的理解
// 头结点非空则带着自己的level 1 作为 starter 加入队列
// 如果节点 的 level 大于 答案数组的 level，则构造新数组并加入该节点值
// 要么节点的 level 就 与 答案数组的 level 相应，push_back 到当前 level 的数组就完了
// 然后 把 亲子节点 加入队列（level 自然为 当前节点level+1）
// 转了一圈没有找到跟自己一样的写法
// 但据我分析还是要好于 官解 开头提到的 哈希表记录二元组
// 虽然都是 二元组记录，我这里并没有使用哈希表，
// 在遍历的同时就完成了处理
// 但也显然不如正经的 BFS
// 理解还差了点

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        queue<pair<TreeNode *, int>> que;
        int level = 1;
        int curLevel = 0;
        if (root)
            que.emplace(root, level);

        while (!que.empty())
        {
            pair<TreeNode *, int> head = que.front();
            if (head.second == curLevel)
            {
                res[curLevel - 1].emplace_back(head.first->val);
            }
            else if (head.second > curLevel)
            {
                curLevel++;
                res.emplace_back(1, head.first->val);
            }
            if (head.first->left)
                que.emplace(head.first->left, head.second + 1);
            if (head.first->right)
                que.emplace(head.first->right, head.second + 1);
            que.pop();
        }

        return res;
    }
};