/*
 * Created by hexiaoyu 
 * on 2023/3/18 20:05
 * https://leetcode.cn/problems/integer-break/
 * medium
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        // 1. 数组含义
        // 1.1 dp[i]为数字i拆分成k个数的最大乘积
        vector<int> dp(n + 1);

        // 2. 递推公式
        // dp[i] = j * dp[i - j]; max

        // 3. 初始化
        dp[2] = 2;
        dp[3] = 3;

        // 4. 顺序
        // 5. 举例
        int max = 0;
        for(int i = 4; i <= n; i++){
            for(int j = 2; j <= i / 2; j++){
                if(max < j * dp[i - j]) {
                    max = j * dp[i - j];
                }
            }
            dp[i] = max;
        }

        return dp.back();
    }
};