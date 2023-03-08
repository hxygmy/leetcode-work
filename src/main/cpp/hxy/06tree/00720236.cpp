/*
 * Created by hexiaoyu 
 * on 2023/3/8 15:07
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
 * medium
 */

#include "queue"
#include "algorithm"
#include "string"
#include "stack"
#include "unordered_map"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 读完题我就知道这题直接抄答案就行了
class Solution {
public:
    // 解法1 来自代码随想录，递归法
    // 函数确定以root为根的二叉树中节点p、q的最近公共祖先，返回该节点，以root为根的二叉树中中不一定含有p、q
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // 函数出口
        // 如果root是p或q本身，说明找到了p、q 直接返回root，这里相当于告诉了递归的上一层，该子树中含有寻找的节点
        // 如果root不存在则返回null
        if (root == q || root == p || !root) return root;

        // 单层递归逻辑
        // 在root的左右子树中分别寻找p、q的最近公共祖先
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 如果左子树和右子树中都找到了返回值，那一定是一边返回p，另一边返回q，则root就是最小公共祖先
        if (left != NULL && right != NULL) return root;

        // 如果左右子树中只有一个找到了公共祖先，则返回另一个子树的根节点
        if (left == NULL && right != NULL) return right;
        else if (left != NULL && right == NULL) return left;
        // 如果左右子树都没找到则没有
        else return NULL;
    }


    // 解法2 来自leetcode官方题解，非递归先序遍历（深度优先遍历）
    // 记录father节点，即<当前节点的值，当前节点的父节点>
    unordered_map<int, TreeNode*> fa;
    // 记录遍历过的节点
    unordered_map<int, bool> vis;
    // 在dfs的时候，把每个节点的父节点记录为键值对
    void dfs(TreeNode* root){
        if (root->left != nullptr) {
            fa[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != nullptr) {
            fa[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val] = nullptr;
        // 把整个二叉树都存入map
        dfs(root);
        // 从给定的p节点向上遍历，vis记录所有遍历过的节点
        while (p != nullptr) {
            vis[p->val] = true;
            p = fa[p->val];
        }
        // 从给定的q节点向上遍历，直到在vis map中找到相同的节点，即为最近公共祖先
        while (q != nullptr) {
            if (vis[q->val]) return q;
            q = fa[q->val];
        }
        return nullptr;
    }

    // 解法3， 不知死活的我自己看能不能写出来一个递归写法
    // 全局变量，记录答案
    TreeNode *res;
    TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q) {
        find_p_q(root, p, q);
        return res;
    }

    // 1. 确定递归函数的参数和返回类型
    // 1.1该递归函数确定以root为根的二叉树中能不能找到p或q节点
    bool find_p_q(TreeNode *root, TreeNode *p, TreeNode *q){
        // 2. 确定递归函数的出口
        // 2.1 如果root为空，则返回找不到
        if(!root) return false;
        // 2.2 如果root就是p或q，则返回找到了
        if(root->val == p->val or root->val == q->val) return true;

        // 3. 单层递归逻辑
        // 3.1 记录root的左右子树是否能找到p、q，一边找到就算找到了
        bool left = find_p_q(root->left, p, q);
        bool right = find_p_q(root->right, p, q);
        // 3.2 如果左右都找到了，说明找到了最近公共祖先
        if((left and right) or ((root->val == p->val or root->val == q->val) and (left or right))) {
            res = root;
        }
        return left or right;
    }
};