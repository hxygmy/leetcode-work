// 常考！！！
// 是个 hard，仅在于思路困难，或者面试官非要 多种解法
// 只要思路清晰，就十分简单，暴力优化起来也很简单（指备忘录优化 空间复杂度 O(N）)
// 第一类思路： 逐下标位置雨水累加
// 第二类思路： 单调栈 逐右可容雨水柱，对其逐层计算容雨，累加到结果后，该柱为左侧柱?
// 双指针法理解困难 (空间复杂度 回到 O(1))
// 单调栈法 还没想出 怎么利用单调栈（猪脑过载，无法开始思考，WZGG 明示单调栈了已经）
// 单调栈 逐层扫描，打开新世界的大门

#include <vector>
#include <algorithm>

using std::max;
using std::min;
using std::vector;

// 2. 备忘录，与暴力思路相同
// 遍历各个位置得到当前位置接的雨水求和
class Solution
{
public:
    int trap(vector<int> &height)
    {
        const int n = height.size();
        vector<int> l_max(n); // 均含当前下标值
        vector<int> r_max(n);
        l_max.front() = height.front();
        r_max.back() = height.back();
        for (int i = 1; i < n; ++i)
            l_max[i] = max(l_max[i - 1], height[i]);
        for (int i = n - 2; i >= 0; --i)
            r_max[i] = max(r_max[i + 1], height[i]);
        int res = 0;
        for (int i = 0; i < n; ++i)
            res += min(l_max[i], r_max[i]) - height[i];
        return res;
    }
};

// 1. 暴力 合集
// 1.1 --1.0纯暴力 的小优化
// 把自己纳入遍历范围则免去了能否接到水的判断
// 单个位置 从自己开始的 左侧的最高高度与右侧的最高高度的 最小值 为该位置接雨水量
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0;
        for (int i = 1; i < height.size() - 1; ++i)
        {
            int l_max = 0;
            for (int j = 0; j <= i; ++j)
                l_max = max(l_max, height[j]);
            int r_max = 0;
            for (int j = i; j < height.size(); ++j)
                r_max = max(r_max, height[j]);
            res += min(l_max, r_max) - height[i];
        }
        return res;
    }
};
// 1.0 纯暴力
// 单个位置左侧的最高高度与右侧的最高高度的最小值如大于该位置高度，则差值为该位置接雨水量
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0;
        for (int i = 1; i < height.size() - 1; ++i)
        {
            int l_max = 0;
            for (int j = 0; j < i; ++j)
                l_max = max(l_max, height[j]);
            int r_max = 0;
            for (int j = i + 1; j < height.size(); ++j)
                r_max = max(r_max, height[j]);
            int bound = min(l_max, r_max);
            res += bound > height[i] ? bound - height[i] : 0;
        }
        return res;
    }
};