/*
 * Created by hexiaoyu 
 * on 2023/2/14 6:15
 * https://leetcode.cn/problems/move-zeroes/
 * easy
 */
#include "vector"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int i = 0; i < nums.size(); i++){
            if(nums[slow] != 0) {
                slow++;
            } else if (nums[slow] == 0 and nums[i] != 0){
                int tmp = nums[i];
                nums[i] = 0;
                nums[slow++] = tmp;
            }
        }
    }
};
