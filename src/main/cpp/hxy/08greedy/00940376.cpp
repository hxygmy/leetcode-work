/*
 * Created by hexiaoyu 
 * on 2023/3/16 22:11
 * https://leetcode.cn/problems/wiggle-subsequence/
 * medium
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

        // 特殊情况返回
        if(nums.size() <= 1) return nums.size();

        // 去重。这里是从尾部开始去重，因为nums可以直接用pop_back()
        int i = nums.size() - 2;
        int j = i + 1;
        while(i >= 0 and nums[i] == nums[j]) {
            nums.pop_back();
            i--;
            j--;
        }
        if(nums.size() == 1) return 1;


        // 记录答案
        int res = 2;
        // 第一组是正还是负
        bool last = nums[j] > nums[i];
        while (i > 0){
            j--;
            i--;
            // 如果出现一次摆动， 则res++且记录下此次摆动是正还是负
            if(nums[j] != nums[i] and last != (nums[j] > nums[i])){
                res++;
                last = !last;
            }
        }

        return res;
    }
};
