/*
 * Created by hexiaoyu 
 * on 2023/3/6 18:37
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);
        buildChild(root, inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 2);
        return root;
    }


    // 1. 确定递归函数的参数和返回类型
    void buildChild(TreeNode *root,
                    vector<int> &inorder,
                    vector<int> &postorder,
                    int iBegin, int iEnd,
                    int pBegin, int pEnd){
        // 2. 确定函数出口
        if(iBegin >= iEnd) return;

        // 3. 单层递归逻辑
        int i;
        for(i = iBegin; i <= iEnd; i++){
            if(inorder[i] == root->val){
                break;
            }
        }
        if(i > iBegin){
            root->left = new TreeNode(postorder[pBegin + i - iBegin - 1]);
            buildChild(root->left, inorder, postorder, iBegin, i - 1, pBegin, pBegin + i - iBegin - 2);
        }
        if(i < iEnd){
            root->right = new TreeNode(postorder[pEnd]);
            buildChild(root->right, inorder, postorder, i + 1, iEnd, pBegin + i - iBegin, pEnd - 1);
        }
    }
};

int main(){
    Solution *a = new Solution();
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    a->buildTree(inorder, postorder);
    return 0;
}
