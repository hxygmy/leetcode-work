#include <string>

using std::string;

// 1. 强行练习string迭代器以复习C++，遂写出一大坨shit，还调半天，属实不习惯不适应。。。。。。
// 需要多加练习，至于正常写法以后再说吧，。，好费神
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        // 强行练习 string 迭代器
        // 练完再写正常的
        string res;
        auto left = s.cbegin();
        auto right = left;
        int count = 0; // 模拟，左括号+1，右括号-1，归零处理
        while (left != s.cend())
        {
            if (*left == '(')
            {
                right = left + 1;
                ++count;
                while (right != s.cend())
                {
                    if (*right == ')')
                        --count;
                    if (count == 0)
                    {
                        string tmp(left + 1, right);
                        res += tmp;
                        ++right;
                        left = right; // right 是指向当前组的下一个
                        break;
                    }
                    if (*right == '(')
                        ++count;
                    ++right;
                }
            }
            else
            {
                ++left;
            }
        }
        return res;
    }
};