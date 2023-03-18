/*
 * Created by hexiaoyu 
 * on 2023/3/18 19:01
 * https://leetcode.cn/problems/unique-paths/
 * medium
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 1. 数组的含义
        // dp[i][j]表示有几种到达点(i, j)的路径，i,j是从1开始计算的
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // 2. 递推公式
        // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

        // 3. 初始化
        // 第一行和第一列都是1

        // 4. 确定递推顺序
        // 5. 举例
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
