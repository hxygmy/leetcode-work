/*
 * Created by hexiaoyu 
 * on 2023/2/14 6:01
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
 * easy
 */
#include "vector"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int quick = 1;
        int size = nums.size();
        while(quick < size){
            if(nums[slow] == nums[quick]){
                quick++;
            } else {
                nums[++slow] = nums[quick++];
            }
        }
        return slow + 1;
    }
};
