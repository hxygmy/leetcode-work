#include <vector>
#include <algorithm>

using std::swap;
using std::vector;

// 双指针，快排最简单的partition方法的基础
// 今天复习了一下快排，之后偶然看到这个题
// 才反应过来，这要做的就是 最简单的 partition
class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int odd = 0;
        int even = nums.size() - 1;
        while (odd < even)
        {
            if (nums[odd] & 1)
                ++odd;
            else if (!(nums[even] & 1))
                --even;
            else
                swap(nums[odd++], nums[even--]);
        }
        return nums;
    }
};

// 1. 双指针（蠢蛋版）O(N) O(N)。。。。。。。。。。。。。。
// 。。。。，，，，。，。，。，。，。
// 有时候人跟人的差距比人跟猪的差距都大。。。。。。。。。
// 有点烦，不烦了再学高手的题解
// 我这写的也太蠢了，看别人写的之前感觉还行。。。。。。。。
class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        int pOdd = 0;
        int pEven = n - 1;
        for (const auto &num : nums)
        {
            if (num & 1)
                res[pOdd++] = num;
            else
                res[pEven--] = num;
        }
        return res;
    }
};