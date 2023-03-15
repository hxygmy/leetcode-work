/*
 * Created by hexiaoyu 
 * on 2023/3/15 12:58
 * https://leetcode.cn/problems/subsets-ii/
 * medium
 */
#include "vector"
#include "algorithm"

using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void d_bt(vector<int> &nums, int seq){
        res.push_back(path);
        if(seq == nums.size()) return;
        for(int i = seq; i < nums.size(); i++){
            path.push_back(nums[i]);
            d_bt(nums, i + 1);
            path.pop_back();
            while(i < nums.size() - 1 and nums[i] == nums[i + 1]) i++;
        }
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        d_bt(nums, 0);
        return res;
    }
};
