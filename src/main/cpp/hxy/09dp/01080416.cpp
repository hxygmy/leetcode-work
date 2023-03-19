/*
 * Created by hexiaoyu 
 * on 2023/3/18 22:05
 * https://leetcode.cn/problems/partition-equal-subset-sum/
 * medium
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum % 2 == 1) return false;
        int target = sum / 2;

        // 开始 01背包
        for(int i = 0; i < nums.size(); i++) {
            for(int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target) return true;
        return false;
    }
};