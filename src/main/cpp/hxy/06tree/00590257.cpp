/*
 * Created by hexiaoyu 
 * on 2023/3/5 17:27
 * https://leetcode.cn/problems/binary-tree-paths/
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

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> paths;
        traversal(root, paths, res);
        return res;
    }

    void traversal(TreeNode *root, vector<int> &path, vector<string> &paths){
        if(root) path.push_back(root->val);
        if(!root->left and !root->right){
            string sPath;
            for(int i = 0; i < path.size() - 1; i++){
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            paths.push_back(sPath);
            return;
        }
        if(root->left){
            traversal(root->left, path, paths);
            path.pop_back();
        }
        if(root->right){
            traversal(root->right, path, paths);
            path.pop_back();
        }
    }

};
