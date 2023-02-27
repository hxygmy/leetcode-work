/*
 * Created by hexiaoyu 
 * on 2023/2/27 19:22
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/
 * medium
 */

#include "vector"
#include "queue"

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;

        queue<TreeNode*> que;
        TreeNode *point = root;

        // 根节点入队
        que.emplace(root);

        vector<int> this_level;
        int this_level_num = 1;
        int next_level_num = 0;

        while(!que.empty()){
            // 取队首元素
            point = que.front();
            que.pop();
            this_level_num--;
            this_level.push_back(point->val);

            if(point->left) {
                que.emplace(point->left);
                next_level_num++;
            }
            if(point->right) {
                que.emplace(point->right);
                next_level_num++;
            }

            // 如果本层元素取完了，把收集好的元素放入vector，开始取下层元素
            if(this_level_num == 0) {
                res.push_back(this_level);
                this_level.clear();
                this_level_num = next_level_num;
                next_level_num = 0;
            }
        }
        return res;
    }
};

