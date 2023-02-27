/*
 * Created by hexiaoyu 
 * on 2023/2/27 19:13
 * https://leetcode.cn/problems/binary-tree-inorder-traversal/
 * easy
 */

#include "vector"
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
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root){
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }

    vector<int> inorderTraversal2(TreeNode* root) {
        stack<TreeNode*> s;

        TreeNode *p = root;

        while(!s.empty() or p){
            if(p){
                s.emplace(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }

        return res;
    }
};
