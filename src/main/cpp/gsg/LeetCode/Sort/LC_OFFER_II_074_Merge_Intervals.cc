// 这里 WZGG 给放到 Sort 应该是因为这道题需要 自定义排序
// 自定义排序挺熟练了，却在贪心上少写了半步摔了一大跤（时间跨度长达一天）

#include <vector>
#include <algorithm>

using std::max;
using std::sort;
using std::vector;

// 1. 贪心，单指针即可
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [&](const vector<int> &a, const vector<int> &b)
             {
                 return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
             });
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size();)
        {
            int begin = intervals[i][0], threshold = intervals[i][1];
            while (++i < intervals.size() && intervals[i][0] <= threshold)
                threshold = max(intervals[i][1], threshold);
            res.push_back({begin, threshold});
        }
        return res;
    }
};