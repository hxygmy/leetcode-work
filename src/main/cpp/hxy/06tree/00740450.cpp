/*
 * Created by hexiaoyu 
 * on 2023/3/8 21:15
 * https://leetcode.cn/problems/delete-node-in-a-bst/
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
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* p = root;
        while(p){
            if(p->val == key){
                break;
            } else if(p->val > key){
                p = p->left;
            } else {
                p = p->right;
            }
        }
        if(!p) return nullptr;
        if(p->left)
    }
};
