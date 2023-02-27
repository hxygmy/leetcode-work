/*
 * Created by hexiaoyu 
 * on 2023/2/26 16:59
 * https://leetcode.cn/problems/sliding-window-maximum/
 * difficult
 */
#include "vector"
#include "deque"
using namespace std;


class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;

    }
};

int main(){
    Solution *a = new Solution();
    vector<int> nums = {-7,-8,7,5,7,1,6,0};
    int k = 4;
    a->maxSlidingWindow(nums, k);
    return 0;

}