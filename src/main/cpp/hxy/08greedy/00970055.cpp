/*
 * Created by hexiaoyu 
 * on 2023/3/17 3:34
 * https://leetcode.cn/problems/jump-game/
 * medium
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        if(nums[0] == 0) return false;
        int threshold = 0;

        // 最后一位不用算
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i] <= threshold){
                threshold++;
            } else {
                threshold = 0;
            }
        }
        return threshold == 0;
    }
};
