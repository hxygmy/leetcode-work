// ！！！！！意外收获！！！！！
// 上取整除法 a / b 上取整 = (a + b - 1) / b
// 注意不要越界
#include <climits>
#include <vector>
#include <algorithm>

using std::max;
using std::vector;

// 2. shit 练习法 --- 记录一下这种练习方法
// 练习 二分搜索法
// 练习，和上面的同样的基本二分查找，难点还是在思路上，
// 这里不再拆分成函数，写成一大坨 shit，把代码写乱，
// 思路反而因为 要写 凌乱的代码，更加清晰了
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int minSpeed = 1;
        int maxSpeed = INT_MIN;
        int k;
        for (const auto &count : piles)
        {
            maxSpeed = max(maxSpeed, count);
        }

        while (minSpeed <= maxSpeed)
        {
            int testSpeed = minSpeed + (maxSpeed - minSpeed) / 2;
            int testTime = 0;
            for (const auto &count : piles)
            {
                testTime += (count - 1 + testSpeed) / testSpeed;
            }

            if (testTime <= h)
            {
                k = testSpeed;
                maxSpeed = testSpeed - 1;
            }
            else
            {
                minSpeed = testSpeed + 1;
            }
        }

        return k;
    }
};

// 1. 二分查找，难点在思路，如何分析出解法二分查找，
// 我是猪脑过载了，看到二分查找标签都没反应过来
// 还得看看别人是咋做的才能反映过来 这道题是怎么回事，是要干什么

// 上取整除法 a / b 上取整 = (a + b - 1) / b
// 注意不要越界
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int maxSpeed = getMaxSpeed(piles);
        int minSpeed = 1;
        int k = maxSpeed;
        while (minSpeed <= maxSpeed)
        {
            int testSpeed = minSpeed + (maxSpeed - minSpeed) / 2;
            // (low + high) / 2 = low/2 + high/2
            // = high - high/2 + low/2
            // = high - (high - low) / 2
            // = low + (high - low) / 2
            // 这得是多久没写了，。，忘完了，还没找到纸
            if (finish(piles, testSpeed, h))
            {
                k = testSpeed;
                maxSpeed = testSpeed - 1;
            }
            else
            {
                minSpeed = testSpeed + 1;
            }
        }
        return k;
    }
    int getMaxSpeed(vector<int> &piles)
    {
        int maxSpeed = INT_MIN;
        for (const auto &count : piles)
        {
            maxSpeed = max(maxSpeed, count);
        }
        return maxSpeed;
    }
    bool finish(vector<int> &piles, int speed, int time)
    {
        int spend = 0;
        for (const auto &count : piles)
        {
            spend += (count + speed - 1) / speed;
        }
        return spend <= time;
    }
};