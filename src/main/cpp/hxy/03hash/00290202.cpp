/*
 * Created by hexiaoyu 
 * on 2023/2/23 17:28
 * https://leetcode.cn/problems/happy-number/
 * easy
 */
#include "unordered_set"

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int p = n;
        int times = 0;

        unordered_set<int> flag;

        while (true) {
            if(flag.find(p) != flag.end()) return false;
            flag.insert(p);
            while (p != 0) {
                times += (p % 10) * (p % 10);
                p /= 10;
            }
            p = times;
            times = 0;
            if(p == 1) return true;
        }
    }
};
