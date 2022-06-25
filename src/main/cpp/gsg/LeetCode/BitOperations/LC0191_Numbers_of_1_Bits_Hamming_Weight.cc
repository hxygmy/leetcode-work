#include <stdint.h> // uint32_t INT_MAX INT_MIN ...

// 3. n & (n-1) 取得 n 减去 最后一个 1 的值，迭代 n
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        long count = 0;
        while (n)
        {
            ++count;
            n &= (n - 1);
        }
        return count;
    }
};

// 2. n&-n 取得 最后一个一，减去它，迭代
int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n)
    {
        ++count;
        n -= n & -n;
    }
    return count;
}

// 1. 暴力遍历
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n)
        {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};