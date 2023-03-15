/*
 * Created by hexiaoyu 
 * on 2023/3/15 11:46
 * https://leetcode.cn/problems/restore-ip-addresses/
 * medium
 */
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> path;

    // 切割问题，回溯法
    // 1. 确定递归函数的参数和返回类型
    void ip_backtracking(string &s, int seq){
        // 2. 确定函数出口
        // 此时还剩下几个元素
        int rest = s.size() - seq;
        int rest_group = 4 - path.size();
        if(rest_group > rest or 3 * rest_group < rest) return;
        if(seq >= s.size()){
            string path_tmp;
            int i;
            for(i = 0; i < 3; i++){
                path_tmp += path[i];
                path_tmp.push_back('.');
            }
            path_tmp += path[3];
            res.push_back(path_tmp);
            return;
        }

        // 3. 单层递归逻辑
        string subs;
        int count;
        for(int i = seq; i < s.size() and i - seq <= 2; i++){
            count = i - seq + 1;
            subs = s.substr(seq, count);
            if((count == 1 or subs[0] != '0') and stoi(subs) <= 255){
                path.push_back(subs);
                ip_backtracking(s, i + 1);
                path.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        ip_backtracking(s, 0);
        return res;
    }
};
