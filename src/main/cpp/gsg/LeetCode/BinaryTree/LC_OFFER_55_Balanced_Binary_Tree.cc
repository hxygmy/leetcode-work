#include <math.h>

#include <algorithm>

using std::abs;
using std::max;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(NULL) {}
};

// 2. WZGG 的聪明写法
// 巧妙 trick：balanced成员变量，
// 求高度同时（普通递归求法）判定以剪枝，
// 非balanced则不再继续向下陷入递归，只返回
// 可多点（入口，返回点）判断剪枝以追求更佳剪枝效果（但我觉得大可不必）
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        height(root);
        return balanced;
    }

    int height(TreeNode *root)
    {
        // WZGG 原始 root在前，分开写的
        if (balanced == false || root == nullptr)
        {
            return 0;
        }

        int left = height(root->left);
        // 可选剪枝
        // if (balanced == false)
        // return 0;

        int right = height(root->right);
        // 可选剪枝
        // if (balanced == false)
        // return 0;

        if (abs(left - right) > 1)
        {
            balanced = false;
        }

        return max(left, right) + 1;
    }

private:
    bool balanced = true;
};

// 1. 我的 笨办法 shit 上 叠 shit（，。，。）
// 为什么能跑这么快
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        int left = 0, right = 0;
        height(root->left, 0, left);
        height(root->right, 0, right);
        if (abs(left - right) > 1)
        {
            return false;
        }

        // return (root->left ? isBalanced(root->left) : 1) && (root->right ?  isBalanced(root->right) : 1);
        return isBalanced(root->left) && isBalanced(root->right);
    }

    void height(TreeNode *root, int h, int &maxH)
    {
        if (root == nullptr)
        {
            maxH = max(maxH, h);
            return;
        }

        ++h;

        height(root->left, h, maxH);
        height(root->right, h, maxH);
    }
};