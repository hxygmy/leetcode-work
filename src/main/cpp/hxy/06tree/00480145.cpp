/*
 * Created by hexiaoyu 
 * on 2023/2/27 18:44
 * https://leetcode.cn/problems/binary-tree-postorder-traversal/
 * easy
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root){
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            res.push_back(root->val);
        }
        return res;
    }

    vector<int> postorderTraversal2(TreeNode* root) {
        stack<TreeNode*> s;

        TreeNode *p = root;
        TreeNode *tmp;

        while(!s.empty() or p){
            if(p) {
                s.emplace(p);
                p = p->left;
            } else {
                p = s.top();
                if(p->right and p->right != tmp){
                    p = p->right;
                    s.emplace(p);
                    p = p->left;
                } else {
                    p = s.top();
                    s.pop();
                    res.push_back(p->val);
                    tmp = p;
                    p = nullptr;
                }
            }
        }
        return res;
    }
};
