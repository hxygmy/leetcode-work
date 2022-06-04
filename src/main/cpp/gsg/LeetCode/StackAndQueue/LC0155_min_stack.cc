// 非常值得记录的一道 easy
// 脑洞大开，打开新世界（除了 stack + map 暴力到不想写）

// 暴露问题 ：  ?(三目运算符) 后面 不能直接 {}构造对象

#include <stack>
#include <map>
#include <utility>
#include <algorithm>

using std::map;
using std::min;
using std::pair;
using std::stack;

// 4. 最爽写法：stack存pair，first真实元素，second对应最小值
// 原理上同于存对象，但用pair太香了，对象的先略了，节省时间
// 暴露问题 ：  ?(三目运算符) 后面 不能直接 {}构造对象
class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (stackWithCurMin.empty() || val < stackWithCurMin.top().second)
        {
            stackWithCurMin.push({val, val});
        }
        else
        {
            stackWithCurMin.push({val, stackWithCurMin.top().second});
        }
    }

    void pop()
    {
        stackWithCurMin.pop();
    }

    int top()
    {
        return stackWithCurMin.top().first;
    }

    int getMin()
    {
        return stackWithCurMin.top().second;
    }

private:
    stack<pair<int, int>> stackWithCurMin;
};

// 3. 一个栈（double count elements）
// 注意 top 和 getmin 有一个要倒腾，
// 取决于 每对元素的相应位置（真正元素 -- 对位最小值）
class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        int newMin = doubleStack.empty() ? val : min(doubleStack.top(), val);
        doubleStack.push(val);
        doubleStack.push(newMin);
    }

    void pop()
    {
        doubleStack.pop();
        doubleStack.pop();
    }

    int top()
    {
        int realTop = doubleStack.top();
        doubleStack.pop();
        int ret = doubleStack.top();
        doubleStack.push(realTop);
        return ret;
    }

    int getMin()
    {
        return doubleStack.top();
    }

private:
    stack<int> doubleStack;
};

// 2. 优雅写法stack+stack，短路或 (empty() || top())
class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        basicStack.push(val);
        minStack.push(minStack.empty() || val < minStack.top() ? val : minStack.top());
    }

    void pop()
    {
        basicStack.pop();
        minStack.pop();
    }

    int top()
    {
        return basicStack.top();
    }

    int getMin()
    {
        return minStack.top();
    }

private:
    stack<int> basicStack;
    stack<int> minStack;
};

// 1. stack + map 属于是十分暴力的解法
class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        minStack.push(val);
        ++minMap[val];
    }

    void pop()
    {
        if (--minMap[minStack.top()] == 0)
            minMap.erase(minStack.top());
        minStack.pop();
    }

    int top()
    {
        return minStack.top();
    }

    int getMin()
    {
        return minMap.begin()->first;
    }
    stack<int> minStack;
    map<int, int> minMap;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */