#include <queue>

using std::queue;

// 终于悟出 "掉头法" （对标 两个栈实现队列的 一个入队栈 + 一个出队栈），
// 既然这样就把 忽略记录 的 两个栈实现队列也搞进来吧

// 2. "掉头法"
// 这里就与栈有差异了，需要理解而不能只是有点感觉就能顺畅写对代码了
// 入栈  队列掉头（入空队，再push整个非空队），
// 始终保持一个队列是空的，另一个队列 出队 即为 栈的弹栈
// 相对于 每次倒腾两次，平均减少了近一半的倒腾操作次数
// 效率提升这点 也 有别于 两个栈实现队列的（看运气，均摊下来（每次出栈倒腾一次）很快，但有时可能会很慢）
class MyStack
{
public:
    MyStack()
    {
    }

    void push(int x)
    {
        if (q1.empty())
        {
            q1.push(x);
            while (!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else
        {
            q2.push(x);
            while (!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    int pop()
    {
        int ret;
        if (q1.empty())
        {
            ret = q2.front();
            q2.pop();
        }
        else
        {
            ret = q1.front();
            q1.pop();
        }
        return ret;
    }

    int top()
    {
        return q1.empty() ? q2.front() : q1.front();
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
};

// 1. 入栈倒腾，出栈直出（WZGG 说法）
// 这道题记录的原因是：我对 两个队列 实现一个栈 十分不敏感
// 不像 两个栈实现队列 一样，马上就有即视感，一点也不熟悉，甚至有些慌乱
// 实际上，这里的写法甚至跟 两个栈实现队列 完全一样
// 心里不熟悉，没底也不要慌，这跟 两个栈实现队列是一样的
class MyStack
{
public:
    MyStack()
    {
    }

    void push(int x)
    {
        while (!prime.empty())
        {
            tmp.push(prime.front());
            prime.pop();
        }
        prime.push(x);
        while (!tmp.empty())
        {
            prime.push(tmp.front());
            tmp.pop();
        }
    }

    int pop()
    {
        int ret = prime.front();
        prime.pop();
        return ret;
    }

    int top()
    {
        return prime.front();
    }

    bool empty()
    {
        return prime.empty();
    }

private:
    queue<int> prime;
    queue<int> tmp;
};
