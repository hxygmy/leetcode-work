/*
 * Created by hexiaoyu 
 * on 2023/3/16 1:59
 * https://leetcode.cn/problems/assign-cookies/
 * easy
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int res = 0;

        int i = 0, j = 0;
        while(i < g.size() and j < s.size()){
            // 如果当前遍历的位置，s能满足g，就说明满足条件，如果满足不了，就让
            if(g[i] <= s[j]){
                res++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        return res;
    }
};
