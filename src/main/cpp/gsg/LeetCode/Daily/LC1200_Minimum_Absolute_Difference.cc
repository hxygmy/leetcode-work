#include <limits.h> // INT_MAX // C 头文件 放在 C++ 前面

#include <initializer_list> // initializer_list
#include <vector>
#include <algorithm> // sort

using std::initializer_list;
using std::sort;
using std::vector;

// 1. 很少做每日一题，记录一下。。
// 昨天回去路上才想起来为什么要记录，因为自身对语法都不能掌握，习惯也不好，能学的地方还挺多的
// 0. 用 delta 别再叫 diff了！！！！！！
// A. 二维vector 不必 clear 再 push进一个数组，直接 = {{数组元素集合}} 即可
// B. initializer_list <initializer_list>头文件中 待学习，很有用很常用的样子
//
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

                // res.clear();
                // res.push_back({a, b});

                res = {{a, b}}; // 与 clear() 再  push_back 达到同样效果，直接赋值就可以了，我傻了
            }
            else if (diff == minDiff)
            {
                // res.push_back({a, b});

                // 替代上面的 push_back 的合理写法
                res.emplace_back(initializer_list<int>{a, b});
            }
        }

        return res;
    }
};