struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2. 迭代 O(h) O(1)
// 不是 O(logn) ！！！！
// 与高度相关！！！
// 与高度相关！！！
// 与高度相关！！！
// 迭代不只是降低了 空间复杂度 至 O(1)
// 而且更好写！！！
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *p = root;
        while (p)
        {
            if (p->val > val)
            {
                p = p->left;
            }
            else if (p->val < val)
            {
                p = p->right;
            }
            else
            {
                return p;
            }
        }
        return nullptr;
    }
};

// 1. 递归 O(h) O(h)
// 别稀里糊涂地上来说个 O(logn) （n为节点数量）
// 这里与是高度相关的，就记住是 O(h)，
// h 为多少就看情况了，最大是 n，最小约 logn
// 每次看到随手算下具体值，912真题，需要追求熟练，追求速度，不然不可能做完912
// 2^h -1 = n
// 2^h = n+1
// h = log~2~(n+1) // markdown 语法
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->val > val)
        {
            return searchBST(root->left, val);
        }

        if (root->val < val)
        {
            return searchBST(root->right, val);
        }

        return root;
    }
};