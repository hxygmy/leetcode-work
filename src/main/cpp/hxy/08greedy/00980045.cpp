/*
 * Created by hexiaoyu 
 * on 2023/3/17 3:46
 * https://leetcode.cn/problems/jump-game-ii/
 * medium
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    /*
     * 从最后一个数字开始遍历
     * nums[i] >= size - 1 - i?
     */
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int sub = nums.size() - 1;
        int res = 0;
        int i;
        while(sub > 0){
            for(i = 0; i < sub; i++){
                if(nums[i] >= sub - i){
                    res++;
                    sub = i;
                    break;
                }
            }
        }

        return res;
    }
};
