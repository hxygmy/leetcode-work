/*
 * Created by hexiaoyu 
 * on 2023/3/18 16:26
 * https://leetcode.cn/problems/min-cost-climbing-stairs/
 * easy
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 1. 确定数组含义
        // dp[i]表示走到下标为i的台阶，最少需要花多少钱
        vector<int> dp(cost.size() + 1);

        // 2. 递推式
        // dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])

        // 3. 初始化
        dp[1] = 0;
        dp[0] = 0;

        // 4. 确定遍历顺序
        // 5. 举例
        for(int i = 2; i < dp.size(); i++){
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp.back();
    }
};
