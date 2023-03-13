/*
 * Created by hexiaoyu 
 * on 2023/3/13 15:03
 * https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
 * easy
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildNode(nums, 0, nums.size() - 1);
    }

    // 1. 确定递归函数的参数和返回类型
    TreeNode * buildNode(vector<int> nums, int begin, int end){
        // 2. 确定函数出点
        if(begin > end) return nullptr;

        // 3. 单层递归逻辑
        int mid = begin + (end - begin + 1) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = buildNode(nums, begin, mid - 1);
        root->right = buildNode(nums, mid + 1, end);
        return root;
    }
};