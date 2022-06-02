#include <vector>

using std::vector;

// 2. O(N^2)，非常简单，也算是十分直白十分好想到，我咋就看半天写出来个贼难写的O(N^3) 还调半天呢？？？
// 以每个元素为起点开始遍历，累加，当前累加元素数量为奇数则加入结果
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int res = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            int sum = 0;
            for (int j = i; j < arr.size(); ++j)
            {
                sum += arr[j];
                if ((j - i + 1) & 1)
                {
                    res += sum;
                }
            }
        }
        return res;
    }
};

// 1. O(n^3)暴力，要注意边界条件，脑子不清醒时调了半天
// 非常纯，有一说一这么蠢的写法比正常写法还难想到，我真是个天才，搞自己
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int res = 0;
        for (int step = 1; step <= arr.size(); step += 2)
        {
            for (int i = 0; i + step <= arr.size(); ++i)
            {
                for (int j = i; j < i + step; j++)
                {
                    res += arr[j];
                }
            }
        }
        return res;
    }
};