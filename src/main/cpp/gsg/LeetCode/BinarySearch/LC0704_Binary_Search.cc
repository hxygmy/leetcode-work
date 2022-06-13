#include <vector>

using std::vector;

// 2. 基本 递归 二分查找
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }

    int binarySearch(vector<int> &nums, int left, int right, int target)
    {
        if (left > right)
            return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            return binarySearch(nums, mid + 1, right, target);
        if (nums[mid] > target)
            return binarySearch(nums, left, mid - 1, target);
        return mid;
    }
};

// 1. 基本 迭代 二分查找
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};