/*
 * Created by hexiaoyu 
 * on 2023/2/23 1:33
 * https://leetcode.cn/problems/group-anagrams/
 * medium
 */

#include <unordered_map>
#include <algorithm>
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 使用排序
        unordered_map<string, vector<string>> res(strs.size());

        for(string s : strs){
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            res[tmp].emplace_back(s);
        }

        vector<vector<string>> r;
        auto ite = res.begin();
        while(ite != res.end()){
            r.emplace_back(ite->second);
            ite++;
        }
        return r;
    }
};
