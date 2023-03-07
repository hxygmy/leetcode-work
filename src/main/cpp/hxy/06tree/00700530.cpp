/*
 * Created by hexiaoyu 
 * on 2023/3/7 22:27
 * https://leetcode.cn/problems/minimum-absolute-difference-in-bst/
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
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *p = root;
        bool flag = true;
        int min = 0x7FFFFFFF;
        int lastNode = 0;
        while(!st.empty() or p){
            if(p){
                st.emplace(p);
                p = p->left;
            } else {
                p = st.top();
                st.pop();

                // 这里对当前节点进行处理
                if(flag){
                    flag = false;
                } else if (min > abs(p->val - lastNode)){
                    min = abs(p->val - lastNode);
                }
                lastNode = p->val;

                p = p->right;
            }
        }
        return min;
    }
};
