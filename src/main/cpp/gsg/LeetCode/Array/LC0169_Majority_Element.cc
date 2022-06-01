#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;

// 2.1 朴素 擂台法
// 进阶目标：O(n) O(1)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int major = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (major == nums[i])
                ++count;
            else
                --count;
            if (!count)
                major = nums[i], count = 1;
        }
        return major;
    }
};
// 2.2 擂台法 加一刀，好像还变慢了
// 进阶目标：O(n) O(1)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int major = nums[0];
        int count = 1;
        int target = nums.size() & 1 ? nums.size() / 2 + 1 : nums.size() / 2;
        for (int i = 1; i < nums.size(); i++)
        {
            if (major == nums[i])
            {
                if (++count == target)
                    return major;
            }
            else
                --count;
            if (!count)
                major = nums[i], count = 1;
        }
        return major;
    }
};

// 1. 朴素的 map 记录，有空间复杂度
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> memo;
        int target = nums.size() & 1 ? nums.size() / 2 + 1 : nums.size() / 2;
        for (auto ele : nums)
        {
            ++memo[ele];
            if (memo[ele] == target)
                return ele;
        }
        return -1;
    }
};