/*
 * Created by hexiaoyu 
 * on 2023/3/8 21:04
 * https://leetcode.cn/problems/insert-into-a-binary-search-tree/
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(root->val > val){
            if(root->left){
                insertIntoBST(root->left, val);
            } else {
                root->left = new TreeNode(val);
            }
        } else {
            if(root->right){
                insertIntoBST(root->right, val);
            } else {
                root->right = new TreeNode(val);
            }
        }
        return root;
    }
};
