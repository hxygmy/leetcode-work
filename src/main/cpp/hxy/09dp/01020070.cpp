/*
 * Created by hexiaoyu 
 * on 2023/3/18 4:20
 * https://leetcode.cn/problems/climbing-stairs/
 * easy
 */
#include "vector"

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;
        // 1. 确定dp数组的含义
        // 1.1 dp[i]指跳n阶台阶（一次跳1或2阶）有几种跳法
        vector<int> dp(n + 1);

        // 2. 确定递推公式
        // 2.1 dp[i] = dp[i - 1] + dp[i - 2]

        // 3. 初始化
        dp[1] = 1;
        dp[2] = 2;

        // 4. 确定遍历顺序
        // 5. 举例
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
