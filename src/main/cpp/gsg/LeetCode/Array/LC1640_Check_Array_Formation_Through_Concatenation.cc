#include <vector>

using std::vector;

// 1. arr 元素一定与 pieces 整组匹配，入口也自然是 pieces 中某数组的第一个元素,
//    如果没有则直接寄，成功进入就进行整组匹配
// 需要锻炼思维，边界细节需要注意，
// 如使用哈希表记录pieces每个数组的第一个值可大大降低编程难度
class Solution
{
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
    {
        // 因两部分内的每个整数都不相同，pieces内的数组内顺序又不能改变

        // 1. arr 的元素 一定与 pieces 整组连续匹配，若上组结束，新的元素一定与pieces中某一组元素第一个匹配
        for (int i = 0; i < arr.size();)
        {
            bool matched = false;
            for (int j = 0; i < arr.size() && j < pieces.size(); ++j)
            {
                if (arr[i] != pieces[j][0])
                {
                    continue;
                }
                else
                { // 匹配到了新的 数组，必须完全匹配，否则 false
                    for (int k = 0; i < arr.size() && k < pieces[j].size(); i++, k++)
                    {
                        matched = true;
                        if (arr[i] != pieces[j][k])
                            return false;
                    }
                }
            }
            if (!matched)
                return false;
        }
        return true;
    }
};