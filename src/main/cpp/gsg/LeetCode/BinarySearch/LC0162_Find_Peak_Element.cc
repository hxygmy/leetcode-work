#include <vector>

using std::vector;

// 2. 二分搜索
// 舒服了
// 不偷懒也挺好写的，
// 刚才真是饿的不想写了，
// 现在一个 base case 都不用加到前头
// 出口：
//     1. left == right
//     2. mid == left
//     3. mid == right
//     4. 判断是不是山峰，不是再判断在山的哪一边继续二分
//      （可以优化先判断在山的哪一边，再判断是不是山峰，极限减少 判断次数，以应对 判断复杂度较高的情况）
//        现在就是优化后版本，习惯写这样了，但这样 读起来相比 4. 有一点点费力

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        return binarySearch(nums, 0, nums.size() - 1);
    }

    int binarySearch(vector<int> &nums, int left, int right)
    {
        if (left == right)
            return left;
        int mid = left + (right - left) / 2;
        if (mid == left)
            return nums[mid] > nums[mid + 1] ? mid : mid + 1;
        if (mid == right)
            return nums[mid] > nums[mid - 1] ? mid : mid - 1;
        if (nums[mid] > nums[mid - 1])
        {
            if (nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else
            {
                return binarySearch(nums, mid + 1, right);
            }
        }
        else
        {
            return binarySearch(nums, left, mid - 1);
        }
    }
};

// 1. 不讲武德验证题意，
// 代码不应该这样写，可读性极差，这次是不想再修改代码了，能验证题意就行
// 饿了真是啥也不管了
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int res = -1;
        while (++res < nums.size() - 1)
            if (nums[res] > nums[res + 1])
                return res;
        return res;
    }
};