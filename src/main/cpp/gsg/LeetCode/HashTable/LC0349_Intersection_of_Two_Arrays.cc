#include <vector>
#include <unordered_set>

using std::unordered_set;
using std::vector;

// 2. set 的合理写法 题很简单，同样的方法写出来的代码差距也太大了
// 对 C++ 这些语法过于生疏了
// 迭代器构造 set < --->vector 可以互相构造的
// 返回匿名对象（使用 set 的迭代器构造 vector 匿名对象）
class Solution
{
public:
    vector<int>
    intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> res;
        unordered_set<int> memo(nums1.cbegin(), nums1.cend());
        for (const auto &num : nums2)
            if (memo.count(num))
                res.insert(num);
        return vector<int>(res.cbegin(), res.cend());
    }
};

// 1. set 之我的蠢蛋写法
// 两个set，一个vector结果
// 很蠢
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> memo1;
        unordered_set<int> memo2;
        vector<int> res;
        for (const auto &num : nums1)
            memo1.insert(num);
        for (const auto &num : nums2)
            memo2.insert(num);
        for (const auto &num : memo1)
        {
            if (memo2.count(num))
                res.push_back(num);
        }
        return res;
    }
};