/*
 * Created by hexiaoyu 
 * on 2023/3/13 15:49
 * https://leetcode.cn/problems/combinations/
 * medium
 */
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    // 1. 确定回溯函数的参数和返回类型
    void backtracking(int n, int k, int b){
        // 2. 确定终止条件
        if(path.size() == k) {
            res.push_back(path);
            return;
        }

        for(int i = b; i <= n; i++){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }


};
