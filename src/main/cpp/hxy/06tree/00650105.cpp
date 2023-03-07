/*
 * Created by hexiaoyu 
 * on 2023/3/7 18:22
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        buildChild(root, preorder, inorder,
                   1, preorder.size() - 1,
                   0, inorder.size() - 1);
        return root;
    }

    //1. 确定递归函数的参数和返回类型
    void buildChild(TreeNode *root,
                    vector<int> &preorder,
                    vector<int> &inorder,
                    int pBegin, int pEnd,
                    int iBegin, int iEnd){
        // 2. 确定函数出口
        if(iBegin >= iEnd){
            return;
        }

        // 3. 单层递归逻辑
        int i;
        for(i = iBegin; i <= iEnd; i++){
            if(inorder[i] == root->val) break;
        }

        if(i > iBegin){
            root->left = new TreeNode(preorder[pBegin]);
            buildChild(root->left, preorder, inorder,
                       pBegin + 1, pBegin + i - iBegin - 1,
                       iBegin, i - 1);
        }
        if(i < iEnd){
            root->right = new TreeNode(preorder[pBegin + i - iBegin]);
            buildChild(root->right, preorder, inorder,
                       pBegin + i - iBegin + 1, pEnd,
                       i + 1, iEnd);
        }
    }
};