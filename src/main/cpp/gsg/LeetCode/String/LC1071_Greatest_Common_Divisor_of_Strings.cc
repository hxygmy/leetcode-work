// 这道题比预想的还要有货
// 严谨的分析还是有点东西的
// 见 yxc 讲解

#include <string>

using std::string;
// 2. 自 1 的基础上（第二版 -》 第四版），击败 100% 让我停止了思考，没有自己继续想更优解法 就去看答案了
// 实际上离最优解有很大的距离，最优解的 思想 很有东西，开脑洞，从未设想的道路
// 而我连 GCD 都有点难以接受，先到这，慢慢消化吧
// 这里 考虑到了 最大因子串 应该 能被 两串 整除（长度上），这个应该算很明显的事情了，
// 但我到 第四版 才反应过来，而且写得还很不完善
// 但从 解答错误 到 5% 一路提升到 100% ，确实暂时不想动了，甚至看答案前还觉得自己写挺好
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        // 这里区分了长短串，离 最优解 有距离
        // 三目运算符判长短 记得 确认相等的情况，有没有写错
        // 貌似先 赋值，再判断，swap 更合适，现在这写法又蠢又易错
        string &longStr = str1.size() >= str2.size() ? str1 : str2;
        string &shortStr = str1.size() < str2.size() ? str1 : str2; // 要考虑一下相等的情况，不要重了
        string cur;

        // 这里只想到了 短串 一定要能与 长串 自前向后匹配
        // A + B == B + A 貌似才是最佳判 非法 方法
        for (int i = 0; i < shortStr.size(); i++)
        {
            if (shortStr[i] != longStr[i])
                return "";
        }
        cur = shortStr;

        while (cur.size() > 0)
        { // 合法的 cur 一定能被 shortStr 整除，也应能被 longStr 整除，这里有伏笔了
            if ((shortStr.size() % cur.size() == 0))
            {
                int times = shortStr.size() / cur.size();
                string tmp = cur;
                while (--times)
                    tmp += cur;
                if (tmp == shortStr)
                {
                    if (longStr.size() % cur.size() == 0)
                    {
                        times = longStr.size() / cur.size();
                        tmp = cur;
                        while (--times)
                            tmp += cur;
                        if (tmp == longStr)
                            return cur;
                    }
                    // 这里不能改变 cur ，可能动了之后，满足了 long 又不满足 short了
                }
            }
            cur.pop_back();
        }
        return "";
    }
};

// 1. 暴力，这是第二版，刚反映到 先 满足 短串 与长短自前向后应完全匹配
// 且 因 短串 短，从短串自长向短遍历更有效率（实际应直接找最大公因数）
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        // 这里区分了长短串，离 最优解 有距离
        // 三目运算符判长短 记得 确认相等的情况，有没有写错
        // 貌似先 赋值，再判断，swap 更合适，现在这写法又蠢又易错
        string &longStr = str1.size() >= str2.size() ? str1 : str2;
        string &shortStr = str1.size() < str2.size() ? str1 : str2; // 要考虑一下相等的情况，不要重了
        string cur;

        // 这里只想到了 短串 一定要能与 长串 自前向后匹配
        // A + B == B + A 貌似才是最佳判 非法 方法
        for (int i = 0; i < shortStr.size(); i++)
        {
            if (shortStr[i] != longStr[i])
                return "";
        }
        cur = shortStr;

        while (cur.size() > 0)
        {
            string tmp = cur;
            while (tmp.size() <= shortStr.size())
            {
                if (tmp == shortStr)
                {
                    string res = cur;
                    // while (res.size() > 0)
                    // {
                    string resGenerator = res;
                    while (resGenerator.size() <= longStr.size())
                    {
                        if (resGenerator == longStr)
                            return res;
                        resGenerator += res;
                    }
                    // res.pop_back(); // 这里不应该再修改了，本应满足 long 的基础上 满足 short，这里修改后可能 满足 short 缺 不满足 long
                    // }
                }
                tmp += cur;
            }
            cur.pop_back();
        }
        return "";
    }
};