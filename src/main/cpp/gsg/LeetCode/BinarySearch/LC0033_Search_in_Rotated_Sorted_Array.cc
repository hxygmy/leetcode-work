// 用不同的写法（迭代 --》 递归）也能加深理解，理清思路
// 几乎全方位优于 没太多意义的整活

// 在无重复数据的循环有序数组中查找元素：
// 1. 命中 target，完成任务
// 2. 未命中：mid 将 循环数组的 [left, right]
//              划分为 [left, mid) (mid, right]
//              这两个区间至少有一边是严格有序的
//              则如果 target 在有序区间中，在有序区间查找即可（二分）
//              如果 target 不在有序区间中，则去另一边查找（二分，未命中则再次二分为有序，无序…………直至命中，太妙了，太妙了，太妙了，太妙了，太妙了，太妙了，太妙了，太妙了，太妙了）

#include <vector>

using std::vector;

// 2. 递归 二分查找
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
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < nums[right])
        { // (mid, right] sorted
            if (target > nums[mid] && target <= nums[right])
            {
                return binarySearch(nums, mid + 1, right, target);
            }
            else
            {
                return binarySearch(nums, left, mid - 1, target);
            }
        }
        else
        { // [left, mid) sorted
            if (target >= nums[left] && target < nums[mid])
            {
                return binarySearch(nums, left, mid - 1, target);
            }
            else
            {
                return binarySearch(nums, mid + 1, right, target);
            }
        }
    }
};

// 1. 迭代 二分查找
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
            if (nums[mid] == target)
                return mid;

            if (nums[mid] <= nums[right])
            {
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            else
            {
                if (target >= nums[left] && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};