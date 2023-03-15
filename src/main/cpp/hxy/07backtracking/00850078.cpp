/*
 * Created by hexiaoyu 
 * on 2023/3/15 12:45
 * https://leetcode.cn/problems/subsets/
 * medium
 */
#include "vector"

using namespace std;

class Solution {
public:
    // 排列组合中，这个属于排列问题
    vector<vector<int>> res;
    vector<int> path;

    // 1. 确定递归函数的参数和返回类型
    void subsets_bt(vector<int> &nums, int seq){
        // 2.确定出口
        res.push_back(path);
        if(seq == nums.size()) return;

        // 3. 单层递归逻辑
        for(int i = seq; i < nums.size(); i++){
            path.push_back(nums[i]);
            subsets_bt(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        subsets_bt(nums, 0);
        return res;
    }
};
