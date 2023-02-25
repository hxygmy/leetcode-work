/*
 * Created by hexiaoyu 
 * on 2023/2/25 22:23
 * https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
 * medium
 */

#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) {
            return 0;
        }

        // 1.建立next数组

        // 其实这里不是next数组，而是pm数组，数组位置的数字表示<=此处之前的数组中有几个公共前后缀
        vector<int> pi(m);

        // 此处的i、j理解为两个指针，i遍历数组，j来确定之前有几个元素是重复的，同时也作为值插入pm数组中
        for (int i = 1, j = 0; i < m; i++) {
            // 当没有匹配上的时候，根据pm数组已经算出来的值来确定下一步needle[i]应该与哪个值比较
            while (j > 0 && needle[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            pi[i] = j;
        }

        // 2. 匹配
        // 遵从几乎相同的逻辑
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
};


int main() {
    Solution *a = new Solution();
    string haystack = "ababcaababcaabc";
    string needle = "ababcaabc";
    a->strStr(haystack, needle);
    return 0;
}