// 这里有 1. 模拟相关  2. 部分不模拟
// 提一嘴  模拟擂台 ： 169. 多数元素
// 这个 模拟擂台非常巧妙，还没吃透，有些懒了

#include <string>

using std::string;

// 2. 开脑洞，L不模拟，硬判断，未曾设想的道路

class Solution
{
public:
    bool checkRecord(string s)
    {
        int ACount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'A')
            {
                ++ACount;
                if (ACount == 2)
                    return false;
            }
            else if (i < s.size() - 2 && s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L')
                return false;
        }
        return true;
    }
};

// 1. 模拟：水就一个字
class Solution
{
public:
    bool checkRecord(string s)
    {
        int LSequentialCount = 0;
        int ACount = 0;
        for (auto ele : s)
        {
            if (ele == 'L')
            {
                ++LSequentialCount;
                if (LSequentialCount == 3)
                    return false;
            }
            else
            {
                LSequentialCount = 0;
                if (ele == 'A')
                {
                    ++ACount;
                    if (ACount == 2)
                        return false;
                }
            }
        }
        return true;
    }
};