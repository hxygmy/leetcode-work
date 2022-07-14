// 删除二叉搜索树中的节点
// 这种题原理很难，往往是用来考察编码能力
// 记不住没问题，要写之前准备一下，甚至直接问面试官思路都是可以的
// 在明确了思路之后代码没问题就可以
// ----WZGG jiII 27:17
// 优化思路：非双孩删除合并，且复用

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 1. 143 行的 shit 一把梭，写的很屎但也算是过了。。。
// 看了WZGG的代码十分简洁精妙，但我不是很理解
// 就先维持现状吧，理解没问题就就问题不大
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // Search 要删除的节点和其父节点
        TreeNode *pParentOfDelNode = nullptr;
        TreeNode *pdelNode = root;
        while (pdelNode != nullptr)
        {
            if (pdelNode->val > key)
            {
                pParentOfDelNode = pdelNode;
                pdelNode = pdelNode->left;
            }
            else if (pdelNode->val < key)
            {
                pParentOfDelNode = pdelNode;
                pdelNode = pdelNode->right;
            }
            else
            {
                break; // 不加深嵌套，拿出来写
            }
        }

        if (pdelNode == nullptr)
        { // 不存在需要删除的节点，直接返回就完了
            return root;
        }

        // if (pParentOfDelNode == nullptr)
        // { // 要删除根节点，直接替换即可。。。。这里是多余的，应写到具体处理里面吧
        // }

        if (pdelNode->left == nullptr && pdelNode->right == nullptr)
        { // 要删除的节点没有子节点
            if (pParentOfDelNode == nullptr)
            { // 要删除的是根节点，没有子节点
                root = nullptr;
                // return root; // 统一在最后返回
            }
            else
            { // 非根节点，没有子节点
                if (pParentOfDelNode->val < pdelNode->val)
                {
                    pParentOfDelNode->right = nullptr;
                }
                else
                {
                    pParentOfDelNode->left = nullptr;
                }
            }
        }
        else if (pdelNode->left != nullptr && pdelNode->right != nullptr)
        { // 要删除的节点有两个子节点，这里就不用特殊处理根节点了

            // 1. 找到该节点的右子树的最小节点，替换之
            TreeNode *pre = pdelNode;
            TreeNode *minOfRight = pdelNode->right;
            while (minOfRight->left != nullptr)
            {
                pre = minOfRight;
                minOfRight = minOfRight->left;
            }
            pdelNode->val = minOfRight->val; // 用 右子树最小节点的值 替换 要删除的节点的值

            // 2. 删除该节点右子树的最小节点（该节点一定没有左孩子）
            //（直接递归调用删除可以吗？一定不会再次陷入递归，因为该节点一定不会有两个子节点了）
            // (还是求稳重写吧，已经是 一大坨 shit 了，不在乎这点了，再写一遍)
            if (minOfRight->right == nullptr)
            { // 该节点没有孩子
                if (pre == pdelNode)
                { // 一步没走，原要删除的节点的右节点即为现在要删除的节点
                    pre->right = nullptr;
                }
                else
                { // 如果走了，则现在要删除的一定是左节点
                    pre->left = nullptr;
                }
            }
            else
            { // 该节点只有右孩子
                if (pre == pdelNode)
                { // 一步没走，原要删除的节点的右节点即为现在要删除的节点
                    pre->right = minOfRight->right;
                }
                else
                { // 如果走了，则现在要删除的一定是左节点
                    pre->left = minOfRight->right;
                }
            }
        }
        else if (pdelNode->left != nullptr)
        {
            if (pParentOfDelNode == nullptr)
            { // 要删除根节点，只有左孩子
                root = root->left;
            }
            else
            { // 非根节点，只有左孩子
                if (pParentOfDelNode->val < pdelNode->val)
                {
                    pParentOfDelNode->right = pdelNode->left;
                }
                else
                {
                    pParentOfDelNode->left = pdelNode->left;
                }
            }
        }
        else
        { // pdelNode->right != nullptr
            if (pParentOfDelNode == nullptr)
            { // 要删除根节点，只有右孩子
                root = root->right;
            }
            else
            { // 非根节点，只有右孩子
                if (pParentOfDelNode->val < pdelNode->val)
                {
                    pParentOfDelNode->right = pdelNode->right;
                }
                else
                {
                    pParentOfDelNode->left = pdelNode->right;
                }
            }
        }

        return root;
    }
};