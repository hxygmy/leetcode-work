struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 1. 整活是第一生产力
// 厘清逻辑的最佳方式是整活
// PS: 感谢 clangFormatter 让整活代码有了一点点可读性
class Solution
{
public:
    bool isUnivalTree(TreeNode *root)
    {
        return root ? root->left ? root->right ? root->val == root->left->val && isUnivalTree(root->left) && root->val == root->right->val && isUnivalTree(root->right) : root->val == root->left->val && isUnivalTree(root->left) : root->right ? root->val == root->right->val && isUnivalTree(root->right)
                                                                                                                                                                                                                                                 : true
                    : true;
    }
};

// 2. 瞄了一眼 微扰理论 规范代码 100%
// PS: 已知没有空树
class Solution
{
public:
    bool isUnivalTree(TreeNode *root)
    {
        return dfs(root->val, root);
    }

    bool dfs(int val, TreeNode *root)
    {
        if (!root)
            return true;
        if (root->val != val)
            return false;
        return dfs(val, root->left) && dfs(val, root->right);
    }
};