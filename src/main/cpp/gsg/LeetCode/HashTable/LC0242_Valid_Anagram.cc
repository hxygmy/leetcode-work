#include <algorithm>
#include <string>

using std::sort;
using std::string;

// 6. 合理 哈希写法 之四 （1 3 杂交（快+快=？））
// 脑子被驴踢了，之一是已经遍历了1，遍历2的时候同时减才能提前判定
// 这里的解貌似都不用看，好想没什么意思
// 打住吧

// 5. 合理 哈希写法 之三 实际最快？
// 先通过长度筛一波
// 同时遍历两个字符串 （脑子被驴踢了---》也可以与 合理 之一 杂交？？？ 再同时判定）
// 在遍历 hash 数组
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        int hash[26] = {0};
        for (int i = 0; i < s.size(); ++i)
        {
            ++hash[s[i] - 'a'];
            --hash[t[i] - 'a'];
        }

        for (const auto count : hash)
        {
            if (count)
            {
                return false;
            }
        }

        return true;
    }
};

// 4. 合理 哈希写法 之二 最好看！
// 分别处理完两个字符串，再对哈希数组进行检查
// 另一种合理哈希，只使用一个哈希数组
// 处理完成后判断，存在不为零的情况则false，全为0则true
// 无需在开头处理 base case 两字符串长度不同（一字符串为另一字符串真子串的情况）
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int hash[26] = {0};
        for (const auto &c : s)
            ++hash[c - 'a'];
        for (const auto &c : t)
            --hash[c - 'a'];
        for (const auto &count : hash)
            if (count)
                return false;

        return true;
    }
};

// 3. 合理 哈希写法 之一 会很快？
// 一个哈希数组，处理第二个字符串的同时判断
// 合理的哈希，应该只用一个哈希数组
// 但要注意判断 字符串2 为 字符串1 的真子串的情况，
// 这种情况可能误判---》加base case，
// 两字符串长度不同则一定不为 anagram
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        int hash[26] = {0};
        for (const auto &c : s)
            ++hash[c - 'a'];
        for (const auto &c : t)
            if (--hash[c - 'a'] < 0)
                return false;

        return true;
    }
};

// 2. 笨蛋 哈希写法，比较两个哈希数组
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int hs[26] = {0};
        int ht[26] = {0};
        for (const auto &c : s)
            ++hs[c - 'a'];
        for (const auto &c : t)
            ++ht[c - 'a'];
        for (int i = 0; i < 26; ++i)
            if (hs[i] != ht[i])
                return false;

        return true;
    }
};

// 1. 暴力排序比较（下次再来）
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};