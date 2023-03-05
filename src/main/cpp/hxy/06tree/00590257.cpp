/*
 * Created by hexiaoyu 
 * on 2023/3/5 17:27
 * https://leetcode.cn/problems/binary-tree-paths/
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
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> st;

        TreeNode *p = root;
        vector<string> res;
        string s;

        while(!st.empty() or p){
            if(p){
                s = s + to_string(p->val) + "->";
                st.emplace(p);
                p = p->left;
            } else {
                p = st.top();
                p = p->right;
                if(!p) {
                    res.push_back(s.substr(0,s.size() - 3));
                    s.substr(0, s.size() - 2);
                }
                st.pop();
            }
        }

        return res;
    }
};
