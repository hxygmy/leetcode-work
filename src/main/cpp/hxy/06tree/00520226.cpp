/*
 * Created by hexiaoyu 
 * on 2023/2/28 17:29
 * https://leetcode.cn/problems/invert-binary-tree/
 * easy
 */
#include "vector"
#include "queue"
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;

        // 后序遍历，每层反转
        stack<TreeNode*> st;

        TreeNode *p = root;

        // r起到两重作用哇，原作用为指定是否遍历过右子树，先新加作用为担当左右子树互换的中转。
        TreeNode *r;

        while(!st.empty() or p) {
            if(p){
                st.push(p);
                p = p->left;
            } else {
                p = st.top();
                if(p->right and p->right != r){
                    p = p->right;
                    st.emplace(p);
                    p = p->left;
                } else {
                    st.pop();

                    r = p->left;
                    p->left = p->right;
                    p->right = r;

                    r = p;
                    p = nullptr;
                }
            }
        }
        return root;
    }
};
