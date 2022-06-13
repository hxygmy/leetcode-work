#include <vector>

using std::vector;

// 2. 递归二分，先不写了，这坨 shit 思路写成递归工作量有点大

// 1. 迭代 二分查找，我的 shit 一大坨
// 但还是自己写的好理解，，。。
// 先不学简洁写法了
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = left + (right - left) / 2;
        bool isExist = false;
        vector<int> res({-1, -1});

        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            if (nums[mid] > target)
                right = mid - 1;
            if (nums[mid] == target)
            {
                isExist = true;
                break;
            }
        }
        if (!isExist)
            return res;

        int startLeft = left, startRight = mid;
        int start = startLeft + (startRight - startLeft) / 2;
        while (startLeft <= startRight)
        {
            start = startLeft + (startRight - startLeft) / 2;
            if (nums[start] == target)
            {
                if (start == 0 || nums[start - 1] != target)
                {
                    res[0] = start;
                    break;
                }
                else
                {
                    startRight = start - 1;
                }
            }
            else
            { // 小于 target了
                startLeft = start + 1;
            }
        }

        int endLeft = mid, endRight = right;
        int end = endLeft + (endRight - endLeft) / 2;
        while (endLeft <= endRight)
        {
            end = endLeft + (endRight - endLeft) / 2;
            if (nums[end] == target)
            {
                if (end == nums.size() - 1 || nums[end + 1] != target)
                {
                    res[1] = end;
                    break;
                }
                else
                {
                    endLeft = end + 1;
                }
            }
            else
            { // 大于 target 了
                endRight = end - 1;
            }
        }

        return res;
    }
};