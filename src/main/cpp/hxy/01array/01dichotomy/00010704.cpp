/*
 * Created by hexiaoyu
 * on 2023/1/31 23:50
 * https://leetcode.cn/problems/binary-search/ * 简单
 */

#include <vector>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 1;
        int high = nums.size();
        while(low <= high) {
            if (low == high and nums[low - 1] != target){
                return -1;
            }
            int mid = (low + high) / 2;
            if (nums[mid - 1] == target) {
                return mid - 1;
            } else if (nums[mid - 1] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

        }
        return -1;
    }
};


