// 自己写了极为简单的写法，感觉不对劲
// 应该是数据减弱了，这个题有很大的升级空间
// 如最基础的 防爆栈 等等
// 2022-06-08 的数据随便过

// 2. 一行递归整活（这么简单的逻辑，也不能算整活吧）
class Solution
{
public:
    int multiply(int A, int B)
    {
        return B ? A + multiply(A, B - 1) : 0;
    }
};

// 1. 正经递归
class Solution
{
public:
    int multiply(int A, int B)
    {
        if (B == 0)
            return 0;
        return A + multiply(A, B - 1);
    }
};