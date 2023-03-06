/*
 * Created by hexiaoyu 
 * on 2023/3/6 16:12
 * https://leetcode.cn/problems/sum-of-left-leaves/
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
/*
 * 递归三部曲
 * 1. 确定函数的参数和返回类型
 * 2. 确定递归出口
 * 3. 确定单层递归逻辑
 */
class Solution {
public:
    /*
     * 1. 确定递归函数的参数和返回值
     * 需要求二叉树的左孩子之和，并返回，需要根节点，返回值为int
     */
    int sumOfLeftLeaves(TreeNode* root) {
        // 2. 确定递归出口
        if(!root) return 0;
        int res = 0;
        if(root->left and !root->left->left and !root->left->right) {
            res += root->left->val;
        }
        // 3. 确定单层递归逻辑
        return res + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

/*
 * 执行结果：
通过
 显示详情    查看示例代码  添加备注

执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：12.8 MB, 在所有 C++ 提交中击败了99.91%的用户
通过测试用例：
100 / 100
 */
