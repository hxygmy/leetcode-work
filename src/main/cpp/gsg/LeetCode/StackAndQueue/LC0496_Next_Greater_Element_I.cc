#include <vector>
#include <stack>
#include <unordered_map>

using std::stack;
using std::unordered_map;
using std::vector;

// 2. 单调栈 + 哈希
// 单调栈一出来把别的盖住完了，扯上单调栈这就不是 easy 了
// 现在才发现自己写的 单调栈 貌似是异类写法
// 别人单调栈都是倒着写
// 看起来倒着写确实能少一些答案更新（O(1)操作）
// 但自己写的好理解，多一点 O(1) 行为暂时不管了
// 单调栈这块先这么打住，工作级别不涉及这个知识点
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res(nums1.size());
        stack<int> monotonicStack;
        unordered_map<int, int> memo;
        for (int i = 0; i < nums2.size(); ++i)
        {
            while (!monotonicStack.empty() && nums2[i] > monotonicStack.top())
            {
                memo[monotonicStack.top()] = nums2[i];
                monotonicStack.pop();
            }
            monotonicStack.push(nums2[i]);
            memo[nums2[i]] = -1;
        }

        for (int i = 0; i < nums1.size(); ++i)
        {
            res[i] = memo[nums1[i]];
        }
        return res;
    }
};

// 1. 暴力，先定位（nums1 -> nums2）再在nums2中找答案
// 蠢爆！！！
// 至少应该意识到 哈希 这个点，
// nums1 是 nums2 的子集，且各自内部所有元素互不相同！！！
// 单调栈 应该不是本题用意，最基础的单调栈掂出来也是 medium
//
// 还有读题这件事，一开始看得跑偏太远了
// 也自然是 一个点都没 get 到
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        // 先构建 差分数组
        // 再构建 差分数组 的 前缀和数组 以降到 O(N)？
        // 好像读错题了，要先搜索元素貌似。。。。

        // 简单题先暴力解了。。。待会儿再搞事

        for (int i = 0; i < nums1.size(); ++i)
        {
            bool bigger = false;
            bool find = false;
            for (int j = 0; j < nums2.size(); ++j)
            {
                if (find == false && nums2[j] == nums1[i])
                {
                    find = true;
                    continue;
                }
                if (find && nums2[j] > nums1[i])
                {
                    nums1[i] = nums2[j];
                    bigger = true;
                    break;
                }
            }

            if (false == bigger)
            {
                nums1[i] = -1;
            }
        }

        return nums1;
    }
};