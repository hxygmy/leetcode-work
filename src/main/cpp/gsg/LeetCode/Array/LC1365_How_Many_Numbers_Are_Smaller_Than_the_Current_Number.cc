#include <vector>

using std::vector;

// 1. 哈希数组 计数
// 计数完成后还能继续充当 填充答案的 generator
// 但要特殊处理 为 0 的时候（相对于再整个 key - ans 数组）
// 此版本先前 写了 01.暴力+备忘录； 02.计数 + 备忘录（生成后填充）
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int count[101] = {0}; // 计数，用于实现 O(N) 统计答案
        for (auto ele : nums)
        {
            ++count[ele];
        }
        for (int i = 1; i < 101; i++)
        {
            count[i] += count[i - 1];
        }
        for (auto &ele : nums)
        {
            ele = ele == 0 ? 0 : count[ele - 1];
        }
        return nums;
    }
};