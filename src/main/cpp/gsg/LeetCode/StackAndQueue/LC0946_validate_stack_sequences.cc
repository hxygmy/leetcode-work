#include <vector>
#include <stack>

using std::stack;
using std::vector;

// 1. 直接模拟 (模拟入栈，每次入栈后都尝试弹栈至并不能弹栈，
// 如果可以匹配，则完成操作后 模拟栈一定是空的)
// 太妙了，简单又好写
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int pc = 0; // popped counter;
        stack<int> simulator;
        for (const auto &ele : pushed)
        {
            simulator.push(ele);
            while (!simulator.empty() && simulator.top() == popped[pc])
            {
                simulator.pop();
                ++pc;
            }
        }
        return simulator.empty();
    }
};