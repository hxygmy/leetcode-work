#include <vector>
#include <stack>

using std::stack;
using std::vector;

// 2. 单调栈
// 常规写法，十分简单，十分好写
// 单调栈，正常的写法如此简单，知道套路与不知道套路的差距太大了。
// 多见点题貌似功利上更占优势，还不累
// 并不需要存 value-index 对象  --》 与不原地操作，使用结果数组降低心智负担 配合（，。下面都暴力了还硬原地操作，又累又没结果，不要再这样了，虽然最后闯过去了）
// 通过原数组取值，单调栈存value即可，结果存新的结果数组里面
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> monotonicStack;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i)
        {
            while (!monotonicStack.empty() && temperatures[monotonicStack.top()] < temperatures[i])
            {
                res[monotonicStack.top()] = i - monotonicStack.top();
                monotonicStack.pop();
            }
            monotonicStack.push(i);
        }
        return res;
    }
};

// 1. 暴力解通常只为了理解题意，确认自己的测试用例编写是否合适，对题目的理解是否正确
// 不应上头，硬优化硬过，下面开头那几行并不是当前暴力通过版本思路，是之前的错误思路，但那个错误思路也前进了一小步（只是慢，结果没错）
// 当前看 minRIndex 哈希数组的注释即为有效思路，possible 哈希数组删除，minRIndex就直接起它的效了

// 整活之心不死，继续尝试暴力前缀剪枝
// 成功了一小步
// 整活思路更加明晰了
// 我还是想继续整活
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        bool traversed[101] = {0};
        int minRIndex[101] = {0}; // 记录先前有结果的最大下标对应的 右边的值的下标，如果 大于当前遍历的下标，说明他也是 当前结果的 generator

        for (int i = 0; i < temperatures.size(); ++i)
        {
            bool higher = false;
#if 1
            if (traversed[temperatures[i]] && !minRIndex[temperatures[i]])
            {
                temperatures[i] = 0;
                continue;
            }

            traversed[temperatures[i]] = true;

            if (i < minRIndex[temperatures[i]])
            {
                temperatures[i] = minRIndex[temperatures[i]] - i;
                continue;
            }

#endif
            for (int j = i + 1; j < temperatures.size(); ++j)
            {
                if (temperatures[j] > temperatures[i])
                {
                    higher = true;
                    minRIndex[temperatures[i]] = j;
                    temperatures[i] = j - i;
                    break;
                }
            }
            if (!higher)
                temperatures[i] = 0;
        }

        return temperatures;
    }
};