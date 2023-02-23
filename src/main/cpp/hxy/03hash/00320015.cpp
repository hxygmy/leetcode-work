/*
 * Created by hexiaoyu 
 * on 2023/2/23 19:09
 * https://leetcode.cn/problems/3sum/
 * medium
 */
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        vector<vector<int>> res;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size - 2; i++){
            if(nums[i] > 0) break;
            for(int j = i + 1; j < size - 1; j++){
                if(nums[i] + nums[j] > 0) break;
                int k = j + 1;
                int s_sum = nums[i] + nums[j];
                while(s_sum + nums[k] < 0 and k + 1 < size){
                    k++;
                }
                if (s_sum + nums[k] == 0) {
                    vector<int> ans = {nums[i], nums[j], nums[k]};
                    res.emplace_back(ans);
                }
                while(j < size - 2 and nums[j + 1] == nums[j]){
                    j++;
                }
            }
            while(i < size - 3 and nums[i + 1] == nums[i]){
                i++;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution *a = new Solution();
    auto b = a->threeSum(nums);
    return 0;
}
