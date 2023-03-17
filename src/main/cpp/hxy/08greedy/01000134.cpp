/*
 * Created by hexiaoyu 
 * on 2023/3/18 3:23
 * https://leetcode.cn/problems/gas-station/
 * medium
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int rest = 0;
        int pos = 0;
        int size = gas.size();
        for(int i = 0; i < size; i++){
            rest = rest + gas[i] - cost[i];
            if(rest < 0){
                pos = i + 1;
                rest = 0;
            }
        }

        // 模拟
        int gases = 0;
        for(int j = 0; j < size; j++){
            gases = gases + gas[(j + pos) % size] - cost[(j + pos) % size];
            if(gases < 0) return -1;
        }

        return pos;
    }
};