#include <vector>
#include <unordered_map>

using namespace std;

// 2. Two-Pass Hash Table
// 方便变形拓展
// 最直白的思路直接翻译
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> memo;
        for (int i = 0; i < nums.size(); ++i)
        {
            memo[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (memo.count(target - nums[i]))
            {
                int idx = memo[target - nums[i]];
                if (idx != i)
                {
                    return {i, idx};
                }
            }
        }
        return {};
    }
};

// 1. One-Pass Hash Table
// 特题特解，最好写，也最快
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> valueToKey;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = valueToKey.find(target - nums[i]);
            if (it != valueToKey.cend())
            {
                return {it->second, i};
            }
            else
            {
                valueToKey[nums[i]] = i;
            }
        }

        return {};
    }
};