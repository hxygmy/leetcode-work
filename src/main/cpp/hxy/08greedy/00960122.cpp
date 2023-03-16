/*
 * Created by hexiaoyu 
 * on 2023/3/17 3:21
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
 * medium
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;

        int res = 0;

        for(int i = 0, j = 1; j < prices.size(); i++, j++){
            if(prices[j] > prices[i]){
                res += (prices[j] - prices[i]);
            }
        }
        return res;
    }
};