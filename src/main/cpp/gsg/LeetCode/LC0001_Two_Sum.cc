#include <vector>
#include <unordered_map>

using namespace std;

// 1. one-pass Hash Table
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