/*
 * Created by hexiaoyu 
 * on 2023/2/22 0:35
 * https://leetcode.cn/problems/valid-anagram/
 * easy
 */
#include "string"

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // 定义一个含有26个英文字母的数组，遍历s以增加，遍历t以减少
        int res[26] = {0};
        for(char c : s) {
            res[c - 'a']++;
        }
        for(char c : t) {
            res[c - 'a']--;
        }
        for(int f : res) {
            if(f != 0) return false;
        }
        return true;
    }
};
