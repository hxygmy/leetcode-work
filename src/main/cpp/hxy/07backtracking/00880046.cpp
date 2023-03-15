/*
 * Created by hexiaoyu 
 * on 2023/3/15 15:45
 * https://leetcode.cn/problems/permutations/
 * medium
 */
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> bitmap;

    void permute_bt(vector<int> &nums){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!bitmap[i]){
                path.push_back(nums[i]);
                bitmap[i] = true;
                permute_bt(nums);
                path.pop_back();
                bitmap[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        bitmap.resize(nums.size());
        permute_bt(nums);
        return res;
    }
};
