/*
 * Created by hexiaoyu 
 * on 2023/2/1 0:47
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
 * 中等
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:

    int findLeft(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;

            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target){
                right = mid;
            } else {
                right = mid - 1;
            }
        }
        if (nums[left] == target) {
            return left;
        }
        return -1;
    }

    int findRight(vector<int> &nums, int target, int left) {
        int right = nums.size() - 1;

        while (left < right){
            int mid = (left + right + 1) / 2;

            if (nums[mid] == target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        if (nums.empty()) {
            return {-1, -1};
        }
        //找到开始的位置
        int left = Solution::findLeft(nums, target);
        //找到结束的位置
        int right = Solution::findRight(nums, target, left);

        return {left, right};
    }
};

int main(){
    vector<int> n = {};
    int target = 0;
    Solution a = *new Solution();
    vector<int> res = a.searchRange(n, target);
    return 0;
}
