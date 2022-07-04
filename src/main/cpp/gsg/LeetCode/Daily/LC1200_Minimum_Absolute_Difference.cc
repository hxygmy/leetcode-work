#include <limits.h> // INT_MAX // C 头文件 放在 C++ 前面

#include <vector>
#include <algorithm> // sort

using std::sort;
using std::vector;

// 1. 很少做每日一题，记录一下。。
// 前面有几个值得记录的没有记录
// 这个暂时没发现有啥记录价值，记了就放这吧
class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        vector<vector<int>> res;
        for (int i = 0; i < arr.size() - 1; ++i)
        {
            int a = arr[i];
            int b = arr[i + 1];
            int diff = abs(a - b);

            if (diff < minDiff)
            {
                minDiff = diff;
                res.clear();
                res.push_back({a, b});
            }
            else if (diff == minDiff)
            {
                res.push_back({a, b});
            }
        }

        return res;
    }
};