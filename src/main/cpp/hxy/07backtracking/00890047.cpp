/*
 * Created by hexiaoyu 
 * on 2023/3/15 16:06
 * https://leetcode.cn/problems/permutations-ii/
 * medium
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;
    vector<bool> sb;

    void pu2(vector<int> &nums){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!sb[i]){
                path.push_back(nums[i]);
                sb[i] = true;
                pu2(nums);
                path.pop_back();
                sb[i] = false;
                while(i < nums.size() - 1 and nums[i] == nums[i + 1]) i++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        sb.resize(nums.size());
        pu2(nums);
        return res;
    }
};
