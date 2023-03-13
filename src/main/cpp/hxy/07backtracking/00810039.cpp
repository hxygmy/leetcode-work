/*
 * Created by hexiaoyu 
 * on 2023/3/13 19:13
 * https://leetcode.cn/problems/combination-sum/
 * medium
 */
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    int sum;

    // 1. 递归函数的参数和返回类型
    void recursive(vector<int> candidates, int target, int seq){
        // 2. 函数出口
        if(sum == target){
            res.push_back(path);
            return;
        }
        if(sum > target) return;

        // 3. 单层递归逻辑
        for(int i = seq; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            sum += candidates[i];
            recursive(candidates, target, i);
            path.pop_back();
            sum -= candidates[i];
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        recursive(candidates, target, 0);
        return res;
    }
};
