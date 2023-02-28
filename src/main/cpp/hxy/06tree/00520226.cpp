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
        // 后序遍历，每层反转

    }
};
