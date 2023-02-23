/*
 * Created by hexiaoyu 
 * on 2023/2/23 17:59
 * https://leetcode.cn/problems/two-sum/
 * easy
 */
#include "unordered_map"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> flag;

        for(int i = 0; i < nums.size(); i++) {
            auto pivot = flag.find(target - nums[i]);
            if(pivot == flag.end()){
                flag[nums[i]] = i;
            } else {
                return {flag[target - nums[i]], i};
            }
        }
        return {};
    }
};

int main(){
    vector<int> nums = {3,2,4};
    int target = 6;

    Solution *a = new Solution();
    auto b = a->twoSum(nums, target);
    return 0;
}
