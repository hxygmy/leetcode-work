/*
 * Created by hexiaoyu 
 * on 2023/3/18 4:04
 * https://leetcode.cn/problems/fibonacci-number/
 * easy
 */
#include "vector"

using namespace std;

class Solution {
public:
    int fib(int n) {
        // 出口
        if(n < 2) return n;

        // 单层递归逻辑
        return fib(n - 1) + fib(n - 2);
    }


    /*
     * 确定dp数组（dp table）以及下标的含义
     * 确定递推公式
     * dp数组如何初始化
     * 确定遍历顺序
     * 举例推导dp数组
     */
    int fib2(int n) {
        if(n < 2) return n;
        // 1. 确定dp数组（dp table）以及下标的含义
        // 1.1 dp[i] 用来存放 fib[i];
        vector<int> dp(n + 1);

        // 2. 确定递推公式
        // 2.1 这里题目已经给了dp[i] = dp[i - 1] + dp[i - 2]

        // 3. dp数组如何初始化
        dp[0] = 0;
        dp[1] = 1;

        // 4. 确定遍历顺序
        // 4.1 根据递归公式得出显然是正序遍历

        // 5. 举例推导dp数组
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
