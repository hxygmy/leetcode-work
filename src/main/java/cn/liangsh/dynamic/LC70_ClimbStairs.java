package cn.liangsh.dynamic;

/**
 * @author Liangsh
 * @description 爬楼梯
 * @date 2022/9/8 8:37
 */
public class LC70_ClimbStairs {

    public int climbStairs(int n) {
        if (n <= 1) return n;
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];

    }
}
