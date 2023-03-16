/*
 * Created by hexiaoyu 
 * on 2023/3/16 23:08
 * https://leetcode.cn/problems/maximum-subarray/
 * medium
 */
#include "vector"
#include "algorithm"

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = -10001;
        int sum = -10001;
        int j = 0;
        while(j < nums.size()){
            if(sum < 0) {
                sum = nums[j];
            } else {
                sum += nums[j];
            }

            if(res < sum) res = sum;
            j++;
        }

        return res;
    }
};
