/*
 * Created by hexiaoyu 
 * on 2023/3/15 10:17
 * https://leetcode.cn/problems/combination-sum-ii/
 * medium
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;

    // 1. 确定递归函数的参数和返回类型
    void c2_backtracking(vector<int> &candidates, int& target, int seq){
        // 2. 确定出口
        if(seq > candidates.size() or sum > target) return;
        if(sum == target) {
            res.push_back(path);
            return;
        }

        // 3. 单层递归逻辑
        for(int i = seq; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            sum += candidates[i];
            c2_backtracking(candidates, target, i + 1);
            path.pop_back();
            sum -= candidates[i];
            while(i < candidates.size() - 1 and candidates[i] == candidates[i + 1]) i++;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        c2_backtracking(candidates, target, 0);
        return res;
    }
};
