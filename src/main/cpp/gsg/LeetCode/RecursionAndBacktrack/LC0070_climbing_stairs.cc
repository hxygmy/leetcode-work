#include <vector>

using std::vector;

// Digression 3
// 矩阵快速幂
// 这个 O(logN) 做法 小学生都会
// 但我不会，不写

// Digression 2
// 不带 备忘录 的 动态规划
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int f1 = 1;
        int f2 = 2;
        int res = 0;
        for (int i = 3; i <= n; i++)
        {
            res = f1 + f2;
            f1 = f2;
            f2 = res;
        }
        return res;
    }
};

// Digression 1
// 带 备忘录 的 动态规划 （普通的动态规划）
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// 2. 带备忘录的递归
// 使用的栈空间，递归需要传备忘录，但传引用还能接受
// 这个可以再简短一点，开头的 base case 可以去掉
// 数组长一个就好了，这里不再重复贴代码
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        vector<int> memo(n + 1);
        memo[1] = 1;
        memo[2] = 2;
        return ways(n, memo);
    }
    int ways(int n, vector<int> &memo)
    {
        if (memo[n] != 0)
            return memo[n];
        memo[n] = ways(n - 1, memo) + ways(n - 2, memo);
        return memo[n];
    }
};

// 1. 不带备忘录的递归 已经不能通过了，时间超限
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};