// 今天跟二分查找计划重写了一遍，
// 发现之前写的 都是 稀里糊涂 不清不楚的
// 写的 很屎
// 个人认为主要原因在于 官解 的 误导
// 这个官解也太烂了，还说的很简单的样子。。。。。。。。。。。。
// 贻害无穷

#include <vector>

using std::vector;

// 2. 真合理聪明写法，
// 笨写法 return target < nums[mid] ? mid : mid + 1
// 归纳为 return left
// left == mid  / left == mid+1
// 具体 推导 归纳 见 解 1 说明
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        // return target < nums[mid] ? mid : mid + 1;
        return left;
    }
};

// 1. 真合理笨写法，前面的都是 shit
// 不知道是从哪个出口出来的，故判断一下以返回答案
//（实际上不必，可以归纳出，答案总恰是 left，可以省去判断）
// 只差一点点了，但不是很显眼 target < nums[mid] 的 不是很显眼
// target > nums[mid] 就显然是 left 了 // 有一说一并不是很明显
// 为保持一致就写了两个 mid
// return target < nums[mid] ? mid : mid + 1;
// 记得 最后一次的 right / left 更新前 left == right (mid = left + (right-left)/2; left=mid+1;/right=mid-1;)
// 这样就很好推出 两种出口的结果 都 恰为 left 了
//
// target < nums[mid] ，right 更新为 小于 target的第一个下标（可能越界）
// 此时 mid 也即 left 为 大于 target 的第一个下标（一定合法）为插入位置
//
// target > nums[mid]，left 更新为 大于 target 的第一个下标（可能越界）为插入位置（mid + 1）

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = left + (right - left) / 2;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        return target < nums[mid] ? mid : mid + 1;
    }
};