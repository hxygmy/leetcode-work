#include <string>
#include <stack>

using std::stack;
using std::string;

// 1. 题目很简单，但这次仍值得记录
// ！！！不认真读题，挂了两次！！！还是之前做过的
// 不能因为题目简单而轻视
// 对待每道题都要 认真读题， 认真编写 测试用例
// 第一次：未考虑无右括号匹配，未考虑空栈（也即无左括号），要认真读题
// 第二次：为考虑空栈（也即无左括号），要认真读题

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> memoStack;
        for (auto ele : s)
        {
            switch (ele)
            {
            case '(':
            case '{':
            case '[':
                memoStack.push(ele);
                break;
            case ')':
                if (memoStack.empty() || memoStack.top() != '(')
                    return false;
                memoStack.pop();
                break;
            case '}':
                if (memoStack.empty() || memoStack.top() != '{')
                    return false;
                memoStack.pop();
                break;
            case ']':
                if (memoStack.empty() || memoStack.top() != '[')
                    return false;
                memoStack.pop();
                break;
            }
        }
        return memoStack.empty() ? true : false;
    }
};