// https://leetcode.cn/problems/three-steps-problem-lcci/submissions/
// 暂时不整理了，累了来整理

// 就目前观察到的规律，动态规划远远快于递归
// 过于大的备忘录会极大拖慢时间
// long 空间 换时间有显著效果（少一次 取余），即使备忘录很大
// 这类题解法过于重复，不再重复记录

// 1. 四变量 动态规划
// 这样几乎总是最快的
class Solution
{
public:
    int waysToStep(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        if (n == 2)
            return 2;
        int f0 = 1;
        int f1 = 1;
        int f2 = 2;
        int res = 0;
        for (int i = 3; i <= n; ++i)
        {
            res = ((f0 + f1) % 1000000007 + f2) % 1000000007;
            f0 = f1;
            f1 = f2;
            f2 = res;
        }
        return res;
    }
};