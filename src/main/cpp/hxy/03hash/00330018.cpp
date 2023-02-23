/*
 * Created by hexiaoyu 
 * on 2023/2/23 23:23
 * https://leetcode.cn/problems/4sum/
 * medium
 */
#include "algorithm"
#include "vector"

using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        int size = nums.size();
        if(target <= 0 and nums[0] > 0) return {};
        if(target >= 0 and nums[size - 1] < 0) return {};

        for(int i = 0; i < size - 3; i++){

            for(int j = i + 1; j < size - 2; j++){

                for(int k = j + 1; k < size - 1; k++) {

                    //最内层逻辑
                    int m = k + 1;
                    while(m < size and (long)nums[i] + nums[j] + nums[k] + nums[m] < (long)target){
                        m++;
                    }
                    if(m < size and (long)nums[i] + nums[j] + nums[k] + nums[m] == (long)target){
                        vector<int> ans = {nums[i],nums[j],nums[k],nums[m]};
                        res.emplace_back(ans);
                    }

                    while(k < size - 2 and nums[k] == nums[k + 1]){
                        k++;
                    }
                }

                while(j < size - 3 and nums[j] == nums[j + 1]){
                    j++;
                }
            }

            while(i < size - 4 and nums[i] == nums[i + 1]){
                i++;
            }
        }
        return res;
    }
};
