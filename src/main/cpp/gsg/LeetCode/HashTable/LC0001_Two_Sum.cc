#include <vector>
#include <unordered_map> // 含有 pair了

using namespace std;

// 2. Two-Pass Hash Table
// 方便变形拓展
// 最直白的思路直接翻译
// 土写法（写得快，等效）---> 规范写法见 1. （看起来很牛逼）
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
// 规范写法--》土写法见 2.（写得快，等效）
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
                // valueToKey[nums[i]] = i; // 下面的写法貌似更规范一点
                valueToKey.insert(pair<int, int>(nums[i], i));
            }
        }

        return {};
    }
};