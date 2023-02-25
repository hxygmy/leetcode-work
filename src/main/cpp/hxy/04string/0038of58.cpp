/*
 * Created by hexiaoyu 
 * on 2023/2/25 22:09
 * https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
 * easy
 */

#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        vector<char> tmp(n);
        int i = 0;
        while(i < n){
            tmp[i++] = s[i];
        }

        int left = 0;
        while(i < s.size()){
            s[left++] = s[i++];
        }

        i = 0;
        while(left < s.size()){
            s[left++] = tmp[i++];
        }

        return s;
    }
};
