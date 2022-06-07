#include <vector>
#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;
using std::vector;

// 1. 哈希
// 看到个简单题想练练迭代器的使用，搞半天没搞明白还整出个错误提交
// 想强用迭代器的同时 思路也很凌乱，放弃不用了，改了一堆 shit 通过了
// 现在这个版本是正常的
// ！！！！-----多用 emplace -------------！
// "变参模板" + "完美转发"
// 没有 “临时变量” 或 “发生隐式转换”
class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> memo;
        for (const auto &email : emails)
        {
            string local;
            for (const auto &ele : email)
            {
                if (ele == '+' || ele == '@')
                    break;
                if (ele == '.')
                    continue;
                local.push_back(ele);
            }
            memo.emplace(local + email.substr(email.find('@')));
        }
        return memo.size();
    }
};