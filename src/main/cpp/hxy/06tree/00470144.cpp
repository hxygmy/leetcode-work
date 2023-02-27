/*
 * Created by hexiaoyu 
 * on 2023/2/27 18:13
 * https://leetcode.cn/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root){
            res.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return res;
    }

    // 前序便利非递归算法
    vector<int> preorderTraversal2(TreeNode* root) {
        stack<TreeNode*> s;
        // 遍历指针
        TreeNode *p = root;
        while(!s.empty() or p){
            if(p){
                res.push_back(p->val);
                s.emplace(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }

        return res;
    }
};
