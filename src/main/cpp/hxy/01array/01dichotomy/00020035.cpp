/*
 * Created by hexiaoyu 
 * on 2023/2/1 0:15
 * https://leetcode.cn/problems/search-insert-position/
 * 简单
 */
#include "iostream"
#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            if(low == high and nums[low] != target){
                return nums[low] < target ? low + 1 : low;
            }
            int mid = (low + high) / 2;
            if (nums[mid] == target){
                return mid;
            } else if (nums[mid] < target){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high + 1;
    }
};

int main(){
    vector<int> n = {3,5,7,9,10};
    int target = 8;
    Solution a = *new Solution();
    cout << a.searchInsert(n, target) << endl;
    return 0;
}
