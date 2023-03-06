/*
 * Created by hexiaoyu 
 * on 2023/3/6 17:00
 * https://leetcode.cn/problems/path-sum/
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

class Solution {
public:
    // 1. 题目给的函数可以直接用作递归函数
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 2. 递归出口
        if(!root) return false;
        if(!root->left and !root->right and root->val == targetSum) return true;

        // 3. 单层逻辑
        // targetSum隐藏了回溯的逻辑
        if(root->left and hasPathSum(root->left, targetSum - root->val)) return true;
        if(root->right and hasPathSum(root->right, targetSum - root->val)) return true;
        return false;
    }

    /* 1. 确定递归函数的参数和返回类型
     * 需要一个sum，半途可以根据这个跳出
     * 需要当前处理的节点root，需要bool返回值
     * 2. 确定递归出口
     * 当root是叶节点时，如果root节点的值等于sum，则返回true，不等于则返回false
     * 3. 单层递归逻辑
     * 访问左右孩子，一层层递归，无论哪一层返回true，都直接返回true，自然递归结束则返回false
     */
};
