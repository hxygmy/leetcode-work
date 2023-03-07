/*
 * Created by hexiaoyu 
 * on 2023/3/7 20:13
 * https://leetcode.cn/problems/validate-binary-search-tree/
 * medium
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

// 二叉搜索树的中序遍历一定是单调递增序列
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root->left and !root->right) return true;
        stack<TreeNode*> st;
        TreeNode *p = root;
        pair<bool, int> lastValue = {true, 0};
        while (!st.empty() or p){
            if(p){
                st.emplace(p);
                p = p->left;
            } else {
                p = st.top();
                st.pop();
                if(lastValue.first){
                    lastValue.first = false;
                } else if(lastValue.second >= p->val){
                    return false;
                }
                lastValue.second = p->val;
                p = p->right;
            }
        }
        return true;
    }
};
