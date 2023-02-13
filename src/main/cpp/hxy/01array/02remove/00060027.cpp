/*
 * Created by hexiaoyu 
 * on 2023/2/14 5:38
 * https://leetcode.cn/problems/remove-element/
 * easy
 */
#include "vector"

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        // 双指针法，i是快指针，left是慢指针
        for (int i = 0; i < nums.size(); i++){
            if(nums[i] != val) {
                nums[left++] = nums[i];
            }
        }
        return left;
    }
};
