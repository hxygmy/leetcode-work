// 理解 前缀和 的极佳入门题（理解这么个概念）

#include <vector>

using std::vector;

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// 2. 聪明前缀和
// 前缀和数组 容量 + 1
// 0打头，偏移对应
// 返回就无须判断了，固定式
class NumArray
{
public:
    NumArray(vector<int> &nums)
        : _preSum(nums.size() + 1)
    {
        for (int i = 1; i < _preSum.size(); ++i)
        {
            _preSum[i] += _preSum[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int left, int right)
    {
        return _preSum[right + 1] - _preSum[left];
    }

private:
    vector<int> _preSum;
};

// 1. 笨前缀和，用于开始理解的极佳写法
// 一一对应前缀和，从头开始的需特殊判断
// 暴力就算了不记了没意义
class NumArray
{
public:
    NumArray(vector<int> &nums)
        : _preSum(nums.size())
    {
        _preSum[0] = nums[0];
        for (int i = 1; i < _preSum.size(); ++i)
        {
            _preSum[i] += _preSum[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        return left == 0 ? _preSum[right] : _preSum[right] - _preSum[left - 1];
    }

private:
    vector<int> _preSum;
};
