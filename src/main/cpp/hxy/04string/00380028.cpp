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
        vector<int> pi(m);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && needle[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            pi[i] = j;
        }
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