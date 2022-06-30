// 注意 结果经常因为过大而要求取余
// 使用 宏 或者 成员/静态/全局变量 都是 极好的
// 注意那个 10e9 + 7 是一个整体
// 1000000007

// 1. 踩了很多坑的解
class Solution
{
public:
    int numPrimeArrangements(int n)
    {
        long long primeCount = PrimeCount(n);
        long long notPrimeCount = n - primeCount;
        long long res = 1;

        while (notPrimeCount > 1)
        {
            res *= notPrimeCount--;
            res %= 1000000007;
        }

        while (primeCount > 1)
        {
            res *= primeCount--;
            res %= 1000000007;
        }

        return res;
        // long long res = (prime * notPrime) % 1000000007;

        // long long res = 0;
        // while (notPrime--)
        //{
        //     res += prime;
        //     res = res % 1000000007;
        // }
        // return res;
    }

    int PrimeCount(int n)
    {
        int count = 0;
        for (int i = 2; i <= n; ++i)
        {
            if (isPrime(i))
            {
                ++count;
            }
        }
        return count;
    }

    bool isPrime(int num)
    {
        for (int i = 2; i <= num / 2; ++i)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    // long long factory(long long n)
    //{
    //     // long long res = 1;
    //     // while (n-- > 1)
    //     // {
    //     //     res *= n;
    //     //     if (res > 1000000000)
    //     //     {
    //     //         res = res % 1000000000 + 7;
    //     //     }
    //     //     // res = res % 1000000000;
    //     // }
    //     // return res;
    //
    //    // 递归感觉不是很好进行取余操作
    //    if (n == 1)
    //    {
    //        return 1;
    //    }
    //    return (n % 1000000007) * (factory(n-1) % 1000000007);
    //}
    //
    // int resFactory(int prime, )
};