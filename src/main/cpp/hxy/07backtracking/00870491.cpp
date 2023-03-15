/*
 * Created by hexiaoyu 
 * on 2023/3/15 13:36
 * https://leetcode.cn/problems/non-decreasing-subsequences/
 * medium
 */
#include "vector"
#include "unordered_set"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void f_bt(vector<int> &nums, int seq){
        if(path.size() >= 2) res.push_back(path);
        if(seq == nums.size()) return;

        // 在nums的[0, seq]内维护一个去重参考，如果nums[i]出现过就i++
        unordered_set<int> mul;

        for(int i = seq; i < nums.size(); i++){
            if(path.empty() or nums[i] >= path.back()){
                path.push_back(nums[i]);
                f_bt(nums, i + 1);
                path.pop_back();
            }

            mul.insert(nums[i]);
            while(i < nums.size() - 1 and mul.find(nums[i + 1]) != mul.end()) i++;
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        f_bt(nums, 0);
        return res;
    }
};
