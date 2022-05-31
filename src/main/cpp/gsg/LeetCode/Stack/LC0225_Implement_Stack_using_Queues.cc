#include <queue>

using std::queue;

// 因有top，入栈倒腾，出栈直出
// 题目要求不可使用back

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

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */