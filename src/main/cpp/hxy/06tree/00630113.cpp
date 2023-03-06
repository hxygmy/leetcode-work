/*
 * Created by hexiaoyu 
 * on 2023/3/6 18:08
 * https://leetcode.cn/problems/path-sum-ii/
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

// 和112相比，这个要遍历所有路线
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<int> way;
        vector<vector<int>> res;
        traversal(root, targetSum, way, res);
        return res;
    }

    /*
     * 递归
     * 1. 确定递归函数的参数和返回类型
     * 需要一个节点，用于作为根节点遍历，
     * 需要一个target，保证当前是否满足条件
     * 需要一个vector<int>，存储当前已经找过的路径，
     * 需要一个vector<vector<int>>,存储符合条件的路径
     * 不需要返回值
     * 2. 确定函数出口
     * 遇到叶子节点时，遍历vector<int>如果元素之和等于target，则放入vector<vector<int>>;
     * 3. 单层递归逻辑
     * 遍历左右孩子节点，在vector<int>中添加对应的元素
     */
    void traversal(TreeNode* root, int target, vector<int> &way, vector<vector<int>> &res){
        way.push_back(root->val);
        // 2. 函数出口
        if(!root->left and !root->right){
            int sum = 0;
            for(int i : way){
                sum += i;
            }
            if(sum == target) {
                res.push_back(way);
            }
        }

        // 3. 单层递归逻辑
        vector<int> way_temp = way;
        if(root->left) traversal(root->left, target, way, res);
        if(root->right) traversal(root->right, target, way_temp, res);
    }
};
