/*
 * Created by hexiaoyu 
 * on 2023/3/1 10:39
 * https://leetcode.cn/problems/symmetric-tree/
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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;

        TreeNode* p;
        que.emplace(root);

        int next_level_num = 0;
        int this_level_num = 1;

        vector<TreeNode*> flag;

        while(!que.empty()){
            p = que.front();
            que.pop();
            flag.push_back(p);
            this_level_num--;

            if(p->left){
                que.emplace(p->left);
                next_level_num++;
            }
            if(p->right){
                que.emplace(p->right);
                next_level_num++;
            }

            if(this_level_num == 0){
                if(!isSymmetricArray(flag)) return false;
                flag.clear();
                this_level_num = next_level_num;
                next_level_num = 0;
            }
        }
        return true;
    }
    bool isSymmetricArray(vector<TreeNode*> v){
        int size = v.size();
        int i = 0, j = size - 1;
        while(i <= j){
            if(    (!v[i]->left and v[j]->right)
                or (v[i]->left and !v[j]->right)
                or (!v[i]->right and v[j]->left)
                or (v[i]->right and !v[j]->left)
                or (v[i]->left and v[j]->right and v[i]->left->val != v[j]->right->val)
                or (v[i]->right and v[j]->left and v[i]->right->val != v[j]->left->val)
                ) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
