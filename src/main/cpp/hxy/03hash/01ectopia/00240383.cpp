/*
 * Created by hexiaoyu 
 * on 2023/2/23 1:27
 * https://leetcode.cn/problems/ransom-note/
 * easy
 */
#include "string"

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int res[26] = {0};
        for(char c : magazine){
            res[c - 'a']++;
        }
        for(char c : ransomNote) {
            if(res[c - 'a'] == 0) return false;
            res[c - 'a']--;
        }
        return true;
    }
};