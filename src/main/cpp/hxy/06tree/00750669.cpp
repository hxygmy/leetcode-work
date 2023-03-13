/*
 * Created by hexiaoyu 
 * on 2023/3/12 20:10
 * https://leetcode.cn/problems/trim-a-binary-search-tree/
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

class Solution {
public:
    // 1. 确定递归函数的参数和返回类型
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 2. 确定函数出口
        if(!root) return nullptr;


        // 3. 单层递归逻辑
        if(root->val < low) {
            return trimBST(root->right, low, high);
        }
        if(root->val > high) {
            return trimBST(root->left, low, high);
        }
        if(root->val >= low and root->val <= high){
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }

        return root;
    }
};
