/*
 * Created by hexiaoyu
 * on 2023/1/31 23:50
 * https://www.programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#_704-%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE
 * 简单
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


