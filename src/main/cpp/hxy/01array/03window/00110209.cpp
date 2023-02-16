/*
 * Created by hexiaoyu 
 * on 2023/2/16 20:30
 * https://leetcode.cn/problems/minimum-size-subarray-sum/
 * medium
 */
#include "vector"

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 记录当前区间的元素的和
        int sum = 0;
        // 记录区间开始的位置
        int left = 0;
        // 记录当前区间长度
        int min = 0x7FFFFFFF;
        // 记录当前的区间最小长度
        int res = 0x7FFFFFFF;
        // i为区间结束的位置
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= target) {
                min = i - left + 1;
                if (res > min) {
                    res = min;
                }
                sum -= nums[left];
                left++;
            }
        }
        if (res == 0x7FFFFFFF) {
            return 0;
        }
        return res;
    }
};
