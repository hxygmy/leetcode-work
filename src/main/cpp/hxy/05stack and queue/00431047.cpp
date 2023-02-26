/*
 * Created by hexiaoyu 
 * on 2023/2/26 16:14
 * https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
 * easy
 */

#include "string"

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for(char c : s){
            if(res.empty()) {
                res.push_back(c);
            } else if (c != res.back()) {
                res.push_back(c);
            } else {
                res.pop_back();
            }
        }

        return res;
    }
};
