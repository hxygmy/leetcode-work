#include <string>
#include <unordered_map>

using std::string;
using std::to_string;
using std::unordered_map;

// 1. string 当key 还是有点不讲武德
// id 当 key 闲的蛋疼了再写吧，就这样吧。。。。
// shortUrl --> longUrl
// unordered_map
// 合理解参考 三叶
class Solution
{
public:
    Solution()
        : tinyUrl("http://tinyurl.com/"), id(1)
    {
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string shortUrl = tinyUrl + to_string(id++);
        memo[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return memo[shortUrl];
    }

private:
    unordered_map<string, string> memo;
    string tinyUrl;
    int id;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

// 0. 不讲武德之 不加密也是一种加密
class Solution
{
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));