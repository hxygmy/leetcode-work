/*
 * Created by hexiaoyu 
 * on 2023/2/18 0:18
 * https://leetcode.cn/problems/minimum-window-substring/
 * difficult
 */

#include <unordered_map>
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size() or s.size() == 0) return "";
        // 快慢指针滑动窗口
        int i = 0;
        // 当前最小区间长度
        int len = 0x7FFFFFFF;
        // 区间开始位置
        int start;

        // 存储t的各个字母的频数
        unordered_map<char, int> freq;
        for(char c : t) {
            freq[c]++;
        }
        // 存储还剩多少个字符没找到
        int left = t.size();

        for (int j = 0; j < s.size(); j++){
            // 不满足条件，就继续向后找，直到找到s的结尾
            while(j < s.size() and left > 0) {
                if(freq.find(s[j]) != freq.end()){
                    if(freq[s[j]] > 0) left--;
                    freq[s[j]]--;
                    if (left == 0) break;
                }
                j++;
            }
            if(left > 0) break;

            // 满足条件时慢指针开始移动，移动到下一个包含t中元素的位置
            while(i <= j and left != 1) {
                if (freq.find(s[i]) != freq.end()) {
                    freq[s[i]]++;
                    if (freq[s[i]] > 0) {
                        if(len > j - i + 1) {
                            len = j - i + 1;
                            start = i;
                        }
                        left++;
                    }
                }
                i++;
            }
        }

        if(len == 0x7FFFFFFF) return "";
        return s.substr(start, len);
    }
};
