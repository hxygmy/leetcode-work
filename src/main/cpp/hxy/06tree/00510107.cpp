/*
 * Created by hexiaoyu 
 * on 2023/2/28 17:14
 * https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
 * medium
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
    // 反向层序遍历
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;

        queue<TreeNode*> que;
        stack<vector<int>> st;

        vector<int> tmp;

        TreeNode *p;
        que.emplace(root);
        int this_level_num = 1;
        int next_level_num = 0;

        while(!que.empty()){
            p = que.front();
            que.pop();
            this_level_num--;
            tmp.push_back(p->val);

            if(p->left) {
                que.emplace(p->left);
                next_level_num++;
            }
            if(p->right) {
                que.emplace(p->right);
                next_level_num++;
            }

            if(this_level_num == 0){
                st.push(tmp);
                tmp.clear();
                this_level_num = next_level_num;
                next_level_num = 0;
            }
        }

        while(!st.empty()){
            res.emplace_back(st.top());
            st.pop();
        }

        return res;
    }
};