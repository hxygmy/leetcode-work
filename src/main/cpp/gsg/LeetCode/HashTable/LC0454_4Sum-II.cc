#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;

// 2. O(n^2) 开脑洞，我咋就想不出来呢
// 记录两数之和及其频率，再查找符合条件的另两数之和
// 这时 聪明哈希 与 我写的 傻哈希的差距应该就 十分明显了（傻哈希：搞两个 map 再比较判定，最好写，但太傻了）
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int count = 0;
        unordered_map<int, int> memo12;
        for (const auto &num1 : nums1)
        {
            for (const auto &num2 : nums2)
            {
                ++memo12[num1 + num2];
            }
        }

        for (const auto &num3 : nums3)
        {
            for (const auto &num4 : nums4)
            {
                auto it = memo12.find(0 - (num3 + num4));
                if (it != memo12.cend())
                {
                    count += memo12[0 - (num3 + num4)];
                }
            }
        }

        return count;
    }
};

// 1. O(n^4)暴力验证题意
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int count = 0;
        for (int i = 0; i < nums1.size(); ++i)
        {
            for (int j = 0; j < nums2.size(); ++j)
            {
                for (int k = 0; k < nums3.size(); ++k)
                {
                    for (int l = 0; l < nums4.size(); ++l)
                    {
                        if (nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0)
                        {
                            ++count;
                        }
                    }
                }
            }
        }
        return count;
    }
};