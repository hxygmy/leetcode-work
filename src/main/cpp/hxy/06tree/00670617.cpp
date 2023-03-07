/*
 * Created by hexiaoyu 
 * on 2023/3/7 19:39
 * https://leetcode.cn/problems/merge-two-binary-trees/
 * easy
 */

#include "queue"
#include "algorithm"
#include "string"
#include "stack"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 本题继续使用递归
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 and !root2) return nullptr;
        // 单层递归逻辑
        TreeNode *res;
        if(!root1){
            res = root2;
        }
        if(!root2){
            res = root1;
        }
        if(root1 and root2){
            root1->val += root2->val;
            res = root1;
            res->left = mergeTrees(root1->left, root2->left);
            res->right = mergeTrees(root1->right, root2->right);
        }

        return res;
    }

    // 1. 确定递归函数的参数和返回类型
    void recursiveMerge()
};
