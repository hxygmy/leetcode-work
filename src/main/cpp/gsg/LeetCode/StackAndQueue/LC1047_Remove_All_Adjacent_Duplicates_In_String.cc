// 有连锁反应的消消乐
// 这道题很简单，但 如果进行升级（ 3 消 及以上） 就还是需要一点思路
// 升级版本 用栈模拟 最简单直接 参考解法 2
// 基础版本 根本就不需要栈，使用栈还需要处理结果，直接 string 很香

// !!!!!!!我的诸多 编程陋习 在这道题中爆发!!!!!!!!!
// 1.----------------
// 滥用 size_t 却不多加思索
// 诚然，利用 无符号特性如 -1 为 任意无符号类型的最大值（机器数全为1）是十分常见的
// 但不利用这个特性时，就要十分小心，避免 为其 赋以 负数！！！！！
// 否则往往造成 灾难级后果
// 2.----------------
// 返回字符串答案时，不要手贱 clear 给的字符串，再在上面进行操作
// 虽然是刚用 C++，很少使用 API，也不能过度刻意熟悉API
// 这个 clear 很慢很慢!!!!!!!!!
// 3. 好像没有 3 了，也不是很多吧

#include <string>
#include <stack>
#include <utility>
#include <algorithm>

using std::pair;
using std::reverse;
using std::stack;
using std::string;

// 4. 既然 两消 又不必计数，直接使用栈 它不香吗？
// 前面都在秀些什么
// 特题特解
class Solution
{
public:
    string removeDuplicates(string s)
    {
        string res;
        for (auto ele : s)
        {
            if (!res.empty() && ele == res.back())
            {
                res.pop_back();
            }
            else
            {
                res.push_back(ele);
            }
        }
        return res;
    }
};

// 3. 利用栈模拟（两连消何必计数？）
// 之前只改了一半，是不用技术了，还留着计数。。。。。
// 还好复习了一下，不然都没发现改一半这个盲点，做的时候是真糊涂啊
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> memo;
        for (auto ele : s)
        {
            if (!memo.empty() && ele == memo.top())
                memo.pop();
            else
                memo.push(ele);
        }
        string res;
        while (!memo.empty())
        {
            res.push_back(memo.top());
            memo.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// 2. 利用栈模拟（何不用 pair？）
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<pair<char, int>> memo;
        for (auto ele : s)
        {
            if (!memo.empty() && ele == memo.top().first)
                memo.pop();
            else
                memo.push({ele, 1});
        }
        string res;
        while (!memo.empty())
        {
            res.push_back(memo.top().first);
            memo.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// 1. 用对象存字符及它的数量，存入栈中，进行模拟
// 用 两个栈 分别存 字符 及 数量 也可，但觉得好蠢，不写那种
// 在返回结果上跌了大跤，暴露除了很多问题
string &reverseStr(string &str)
{
    int left = 0;
    int right = str.size() - 1;
    while (left < right)
    {
        char tmp = str[left];
        str[left++] = str[right];
        str[right--] = tmp;
    }
    return str;
}

class Solution
{
public:
    string removeDuplicates(string s)
    {
        for (auto ele : s)
        {
            if (!memo.empty() && ele == memo.top()._c)
                memo.pop();
            else
            {
                CharWithCount newEle(ele, 1);
                memo.push(newEle);
            }
        }
        // s.clear(); // 时间超限
        string res; // 整个新的？
        // if (memo.empty()) return res;
        while (!memo.empty())
        {
            // res.pushba memo.top()._c + res;
            res.push_back(memo.top()._c);
            memo.pop();
        }
        return reverseStr(res);
    }

private:
    class CharWithCount
    {
    public:
        CharWithCount(char c, int count)
            : _c(c), _count(count){

                     };

    public:
        char _c;
        int _count;
    };

private:
    stack<CharWithCount> memo;
};