/*
 * Created by hexiaoyu 
 * on 2023/3/13 16:39
 * https://leetcode.cn/problems/combination-sum-iii/
 * medium
 */
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;

    // 回溯函数的参数和返回类型
    void recursion(int k, int n, int s){
        // 出点
        if(path.size() == k and sum == n){
            res.push_back(path);
            return;
        }
        if(sum > n) {
            return;
        }

        // 单层递归逻辑
        for(int i = s; i <= 9; i++){
            path.push_back(i);
            sum += i;
            recursion(k, n, i + 1);
            path.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        recursion(k, n, 1);
        return res;
    }
};
