/*
 * Created by hexiaoyu 
 * on 2023/3/8 21:15
 * https://leetcode.cn/problems/delete-node-in-a-bst/
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
    // 1. 确定递归函数的参数和返回值
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 2. 确定函数出口
        if(!root) return nullptr;
        if(root->val == key){
            // 没有孩子
            if(!root->left and !root->right){
                return nullptr;
            }
            // 只有左
            if(!root->right){
                return root->left;
            }
            // 只有右
            if(!root->left){
                return root->right;
            }
            // 都有
            TreeNode *par = root;
            TreeNode *p = root->left;
            while(p->right){
                par = p;
                p = p->right;
            }
            root->val = p->val;
            if(par == root) {
                par->left = p->left;
            } else {
                par->right = p->left;
            }
            return root;
        }

        // 3. 单层递归逻辑
        if(root->val > key) root->left = deleteNode(root->left, key);
        if(root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};
