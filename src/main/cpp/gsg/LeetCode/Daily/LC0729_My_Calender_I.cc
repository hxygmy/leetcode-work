// 欠二分解法没写
// 了解线段树的好题？？？

#include <vector>

using std::vector;

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// 1. 暴力，应该再写个二分解，留个坑（本周内填）
class MyCalendar
{
public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (const auto &interval : memo)
        {
            // if ((interval[0] <= start && interval[1] > start)
            // || (interval[0] >= start && interval[0] <= end))
            if ((start <= interval[0] && end > interval[0]) || (start >= interval[0] && start < interval[1]))
            {
                return false;
            }
        }
        memo.push_back({start, end});
        return true;
    }

private:
    vector<vector<int>> memo;
};
