/*
 * Created by hexiaoyu 
 * on 2023/2/25 2:26
 * https://leetcode.cn/problems/reverse-words-in-a-string/
 * medium
 */
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return "";
        string res;
        int left, right;
        int i = s.size() - 1;
        while(i >= 0){
            while(i >= 0 and s[i] == ' '){
                i--;
            }
            if(i == -1) {
                break;
            }
            right = i;

            while(i >= 0 and s[i] != ' '){
                i--;
            }
            left = i + 1;
            while(left <= right){
                res += s[left++];
            }
            res += ' ';
        }
        return res.substr(0, res.size() - 1);
    }
};
