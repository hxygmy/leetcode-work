/*
 * Created by hexiaoyu 
 * on 2023/3/15 11:16
 * https://leetcode.cn/problems/palindrome-partitioning/
 * medium
 */
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    bool isRev(string s){
        for(int i = 0, j = s.size() - 1; i < j; i++, j--){
            if(s[i] != s[j]) return false;
        }
        return true;
    }

    // 1. 确定递归函数的参数和返回值
    void partition_backtracking(string &s, int seq){
        // 2. 确定结束条件
        if(seq >= s.size()){
            res.push_back(path);
            return;
        }

        // 3. 单层递归逻辑
        string subs;
        for(int i = seq; i < s.size(); i++){
            subs = s.substr(seq, i - seq + 1);
            if(isRev(subs)) {
                path.push_back(subs);
                partition_backtracking(s, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        partition_backtracking(s, 0);
        return res;
    }
};
