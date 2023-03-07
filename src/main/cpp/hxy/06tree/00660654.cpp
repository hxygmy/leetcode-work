/*
 * Created by hexiaoyu 
 * on 2023/3/7 19:00
 * https://leetcode.cn/problems/maximum-binary-tree/
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumRecursive(nums, 0, nums.size() - 1);
    }

    // 1. 确定递归函数的参数和返回类型
    TreeNode* constructMaximumRecursive(vector<int> &nums, int begin, int end){
        // 2. 确定函数出口
        if (begin > end) return nullptr;

        // 3. 单层递归逻辑
        int max = begin;
        for(int i = begin + 1; i <= end; i++){
            if(nums[max] < nums[i]) max = i;
        }
        TreeNode *res = new TreeNode(nums[max]);
        if(max > begin) res->left = constructMaximumRecursive(nums, begin, max - 1);
        if(max < end) res->right = constructMaximumRecursive(nums, max + 1, end);
        return res;
    }
};
