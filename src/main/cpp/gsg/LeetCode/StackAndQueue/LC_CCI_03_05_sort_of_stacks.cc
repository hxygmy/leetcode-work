// 非常简单的一道题，但是个 medium 还是尊重一下简单记录

#include <stack>

using std::stack;

// 1. 维持有序：入栈大于栈顶倒腾，倒腾完入栈，入完栈倒腾回来
// 没啥好写的，注意读题！注意读题！注意读题！
// 写测试用例！写测试用例！写测试用例
class SortedStack
{
public:
    SortedStack()
    {
    }

    void push(int val)
    {
        while (!ascend.empty() && ascend.top() < val)
        {
            tmp.push(ascend.top());
            ascend.pop();
        }
        ascend.push(val);
        while (!tmp.empty())
        {
            ascend.push(tmp.top());
            tmp.pop();
        }
    }

    void pop()
    {
        if (!ascend.empty())
            ascend.pop();
    }

    int peek()
    {
        return ascend.empty() ? -1 : ascend.top();
    }

    bool isEmpty()
    {
        return ascend.empty();
    }

private:
    stack<int> ascend;
    stack<int> tmp;
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */