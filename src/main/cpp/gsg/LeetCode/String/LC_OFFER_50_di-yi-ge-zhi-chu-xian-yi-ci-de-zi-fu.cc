#include <unordered_map>
#include <string>

using std::string;
using std::unordered_map;

// 3. 继续开脑洞，延迟删除队列法（也用了哈希表）
// 猪脑过载，先搁这吧

// 2. 开脑洞，哈希记录索引（count ele （已存在）则存不存在的下标标记）
// 遍历 哈希索引 得到 最下合法索引 取出目标值
class Solution
{
public:
    char firstUniqChar(string s)
    {
        unordered_map<char, int> memo;
        for (int i = 0; i < s.size(); ++i)
        {
            if (memo.count(s[i]))
            {
                memo[s[i]] = -1;
            }
            else
            {
                memo[s[i]] = i;
            }
        }
        int first = s.size();
        for (const auto &ele : memo)
            if (ele.second != -1 && ele.second < first)
                first = ele.second;
        return first == s.size() ? ' ' : s[first];
    }
};

// 1. 哈希，遍历两遍 string
class Solution
{
public:
    char firstUniqChar(string s)
    {
        unordered_map<char, int> memo;
        for (const auto &c : s)
        {
            ++memo[c];
        }
        for (const auto &c : s)
        {
            if (memo[c] == 1)
                return c;
        }
        return ' ';
    }
};