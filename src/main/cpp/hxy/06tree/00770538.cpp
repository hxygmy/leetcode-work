/*
 * Created by hexiaoyu 
 * on 2023/3/13 15:32
 * https://leetcode.cn/problems/convert-bst-to-greater-tree/
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

// 看起来像是中序遍历的镜像版，右中左
// 用两种方式来做吧，递归和非递归
class Solution {
public:
    // 非递归版
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *p = root;

        int sum = 0;

        while(!st.empty() or p){
            if(p){
                st.emplace(p);
                p = p->right;
            } else {
                p = st.top();
                st.pop();

                // 处理逻辑
                sum += p->val;
                p->val = sum;

                p = p->left;
            }
        }
        return root;
    }

    // 递归版
    int sum2 = 0;
    TreeNode* convertBST2(TreeNode* root) {
        if(root){
            convertBST(root->right);

            sum2 += root->val;
            root->val = sum2;

            convertBST(root->left);
        }
    }
};
