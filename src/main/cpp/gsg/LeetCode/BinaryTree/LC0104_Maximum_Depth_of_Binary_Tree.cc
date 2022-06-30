#include <algorithm>

using std::max;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 1. 基础的递归解法 res = max(lmax, rmax) + 1;
// 防止自己懒得复习这种解法，只记录个一行整活的
// 迫使自己必须进行有效的思考
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return root == nullptr ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// 0. 我的笨蛋理解 DFS（每个可能的深度都有一个depth，只增不减）
// 合理的 DFS 我是真不理解啊（只用一个depth，加加减减）
// 系统学习到 DFS 了 再回来填坑吧
// 先注重基本的递归解法（max(lmax, right) + 1）
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int depth = 0;
        traverse(root, depth);
        return maxD;
    }

    void traverse(TreeNode *root, int depth)
    {
        if (root == nullptr)
        {
            maxD = max(maxD, ++depth);
            return;
        }
        ++depth;
        traverse(root->left, depth);
        traverse(root->right, depth);
    }

private:
    int maxD = 0;
};