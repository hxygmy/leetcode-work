/*
 * Created by hexiaoyu 
 * on 2023/2/16 20:09
 * https://leetcode.cn/problems/squares-of-a-sorted-array/
 * easy
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums.size() == 0){
            return {};
        }
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--) {
            if (nums[left] * nums[left] > nums[right] * nums[right]) {
                res[i] = nums[left] * nums[left];
                left++;
            } else {
                res[i] = nums[right] * nums[right];
                right--;
            }
        }
        return res;
    }
};