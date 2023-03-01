/*
 * Created by hexiaoyu 
 * on 2023/3/1 16:26
 * https://leetcode.cn/problems/count-complete-tree-nodes/
 * medium
 */

#include "queue"
#include "algorithm"

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
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        // 层次遍历
        queue<TreeNode*> que;
        TreeNode *p;
        int this_level_num = 1;
        int next_level_num = 0;
        int depth = 1;
        que.emplace(root);

        while(!que.empty()){
             p = que.front();
             que.pop();
             this_level_num--;

             if(p->left){
                 que.emplace(p->left);
                 next_level_num++;
             } else {
                 return pow(2, depth) - 1 + next_level_num;
             }
             if(p->right){
                 que.emplace(p->right);
                 next_level_num++;
             } else {
                 return pow(2, depth) - 1 + next_level_num;
             }
             if(this_level_num == 0){
                 if(next_level_num > 0) depth++;
                 this_level_num = next_level_num;
                 next_level_num = 0;
             }
        }
        return 0;
    }
};
