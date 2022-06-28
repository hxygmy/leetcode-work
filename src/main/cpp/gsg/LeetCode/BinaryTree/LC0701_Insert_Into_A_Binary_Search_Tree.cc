// 连续十次提交，这里记录了前三次 shit 一大坨（用于犯糊涂时看的，最好理解）
// 还 挂了两次！！！！！！！！（所以有必要记录最开始写的 shit）
// 4, 5 开始为 合理解，看了 WZGG 的代码 才修改为 合理解，
// 这之间的解都有不等程度的瑕疵

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 5. 合理的递归
// 外部处理空树
// 注意 return 的节省，不再陷入递归，代码就结束了！！！
// 自己一不小心就多写了两个多余的 return
class Solution
{
public:
    void insert(TreeNode *&root, int val)
    {
        if (root->val > val)
        {
            if (root->left == nullptr)
            {
                root->left = new TreeNode(val);
            }
            else
            {
                insert(root->left, val);
            }
        }
        else
        {
            if (root->right == nullptr)
            {
                root->right = new TreeNode(val);
            }
            else
            {
                insert(root->right, val);
            }
        }
    }

    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            root = new TreeNode(val);
            return root;
        }
        insert(root, val);
        return root;
    }
};

// 4. 合理的迭代
// 注意 if 里 return 可节省 else 的使用
// 但不应省时一定不要省（省与不省常见于递归中）
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            root = new TreeNode(val);
            return root;
        }

        TreeNode *p = root;
        while (1)
        {
            if (p->val > val)
            {
                if (p->left == nullptr)
                {
                    p->left = new TreeNode(val);
                    return root;
                }
                p = p->left;
            }
            else
            {
                if (p->right == nullptr)
                {
                    p->right = new TreeNode(val);
                    return root;
                }
                p = p->right;
            }
        }
    }
};

// 3. 只是验证递归不用 外部 base case 的可行性
// 递归 不用 外部 base case 对于 C++ 来说，用引用 几乎可以减去所有 表面上的代价（代码的混乱程度，可读性） 几乎没有，编译器承担了指针的重担
// 这里是 仍是 shit 一大坨
class Solution
{
public:
    void insert(TreeNode *parent, TreeNode *&root, int val)
    {
        if (root == nullptr)
        {
            root = new TreeNode(val);
            if (parent)
            {
                if (parent->val > val)
                {
                    parent->left = root;
                }
                else
                {
                    parent->right = root;
                }
            }

            return;
        }

        if (root->val > val)
        {
            insert(root, root->left, val);
        }
        else
        {
            insert(root, root->right, val);
        }
    }

    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // if (root == nullptr)
        //{
        //     root = new TreeNode(val);
        //     return root;
        // }
        insert(nullptr, root, val);
        return root;
    }
};

// 2. 递归，写傻了，插入不必带上父节点！！！
class Solution
{
public:
    void insert(TreeNode *parent, TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            root = new TreeNode(val);
            if (parent->val > val)
            {
                parent->left = root;
            }
            else
            {
                parent->right = root;
            }
            return;
        }

        if (root->val > val)
        {
            insert(root, root->left, val);
        }
        else
        {
            insert(root, root->right, val);
        }
    }

    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            root = new TreeNode(val);
            return root;
        }
        insert(nullptr, root, val);
        return root;
    }
};

// 1. 迭代，写傻了，插入不必带上父节点！！！
// 插入时再判断插哪边，而不必维持该插哪边的记录
// 感觉这里 迭代 远不如 递归 好写
// 写 迭代 甚至寄了一次。。给自己迭代晕了。。。。
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *p = root;
        TreeNode *pp = nullptr;
        while (p != nullptr)
        {
            if (p->val > val)
            {
                pp = p;
                p = p->left;
            }
            else if (p->val < val)
            {
                pp = p;
                p = p->right;
            }
        }

        p = new TreeNode(val);
        if (pp == nullptr)
        {
            root = p;
        }
        else
        {
            if (pp->val > val)
            {
                pp->left = p;
            }
            else
            {
                pp->right = p;
            }
        }

        return root;
    }
};