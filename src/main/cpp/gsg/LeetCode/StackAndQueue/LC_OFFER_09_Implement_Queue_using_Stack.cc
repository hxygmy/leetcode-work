// 因为这个版本的 数据 比较强，故选此版本，
// 可以明显看到 更优解 与 基本写法的 差距
#include <stack>

using std::stack;

// 2. 一个栈用于入队，另一个栈用于出队
// 均摊 O(1) !!!
// 这个很简单可以想到，也很容易实现
// ！！！重点-------两个队列实现栈--------的优化！！！！！！！！！！！！
// 因为那个 有一点弯，才把这个 很相关 的 大直题 记录再这里
class CQueue
{
public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        in.push(value);
    }

    int deleteHead()
    {
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        if (out.empty())
            return -1; // 在入口写成 in.empty() && out.empty 更易读
        int ret = out.top();
        out.pop();
        return ret;
    }

private:
    stack<int> in;
    stack<int> out;
};

// 1. 基本写法：一个主栈，一个临时栈
// 入栈倒腾，出栈直出（常用，反过来也不是不行）
class CQueue
{
public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        while (!prime.empty())
        {
            tmp.push(prime.top());
            prime.pop();
        }
        prime.push(value);
        while (!tmp.empty())
        {
            prime.push(tmp.top());
            tmp.pop();
        }
    }

    int deleteHead()
    {
        if (prime.empty())
            return -1;
        int ret = prime.top();
        prime.pop();
        return ret;
    }

private:
    stack<int> prime;
    stack<int> tmp;
};
