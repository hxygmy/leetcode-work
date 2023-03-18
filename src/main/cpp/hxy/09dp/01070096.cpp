/*
 * Created by hexiaoyu 
 * on 2023/3/18 21:40
 * https://leetcode.cn/problems/unique-binary-search-trees/
 * medium
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n < 3) return n;
        // 1. dp[i] 是 n 个节点的二叉搜索树可能的情况数量
        vector<int> dp(n + 1);

        // 2. 递推式
        // dp[i] = (dp[i - 1] * dp[0]) + (dp[i - 2] * dp[1]) + (dp[i - 3] * dp[2]) + .... + (dp[0] * dp[i - 1])
        // dp[3] = (dp[2] * dp[0]) + (dp[1] * dp[1]) + (dp[0] * dp[2]) 001122
        // dp[4] = (dp[3] * dp[0]) + (dp[2] * dp[1]) + (dp[1] * dp[2]) + (dp[0] * dp[3]) 00112233 dp[3]

        // 3. 初始化
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        // 4. 顺序
        // 5. 举例
        for(int i = 3; i <= n; i++){
            for(int j = 0; j < i / 2; j++){
                dp[i] += dp[j] * dp[i - 1 - j] * 2;
            }
            if(i % 2  == 1) dp[i] += dp[i / 2] * dp[i / 2];
        }

        return dp[n];
    }
};
