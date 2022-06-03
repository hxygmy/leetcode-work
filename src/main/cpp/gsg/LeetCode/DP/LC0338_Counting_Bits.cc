#include <vector>

using std::vector;

// 2. 简单易理解的一种动规，基础 仅仅是 1.暴力 。没有什么额外知识
// 还有 几种 思路巧妙的 DP 暂时没有学习
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res(n + 1);
        for (int i = 1; i <= n; i++)
        {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};

// 1. 暴力，是一种动态规划的基础，简单观察即可想到动态规划
// 存在 已知规模 但 push_back 的大问题
// 何不直接初始化，下次不要再这样了
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res;
        for (int i = 0; i <= n; i++)
        {
            res.push_back(0);
            int cur = i;
            while (cur > 0)
            {
                if (cur & 1)
                    ++res.back();
                cur >>= 1;
            }
        }
        return res;
    }
};