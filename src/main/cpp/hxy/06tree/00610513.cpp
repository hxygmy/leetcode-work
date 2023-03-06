/*
 * Created by hexiaoyu 
 * on 2023/3/6 16:44
 * https://leetcode.cn/problems/find-bottom-left-tree-value/
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

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // 使用层次遍历，非递归
        queue<TreeNode*> que;
        TreeNode *p;
        que.emplace(root);

        vector<int> this_level;
        while(!que.empty()){
            this_level.clear();
            int size = que.size();
            for(int i = 0; i < size; i++){
                p = que.front();
                que.pop();
                this_level.push_back(p->val);
                if(p->left) que.push(p->left);
                if(p->right) que.push(p->right);
            }
        }
        return this_level[0];
    }
};
