/*
 * Created by hexiaoyu 
 * on 2023/3/19 17:20
 * https://leetcode.cn/problems/last-stone-weight-ii/
 * medium
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];

        // 总重量
        int sum = 0;
        for(int c : stones) sum += c;

        // 1. 确定dp数组的含义
        // 1.1 dp[j] 表示上限重量为i，在stones中选择石头最多可以装多少
        // 2. 递推公式
        // 2.1 dp[j] = max(dp[j], dp[j - stones[j]] + stones[j])
        // 3. 初始化
        int size = sum / 2 + 1;
        vector<int> dp(size, 0);

        // 4. 确定递归顺序
        // 4.1 从大到小，因为需要用到上一层的数据
        // 5. 举例
        for(int i = 0; i < stones.size(); i++){
            for(int j = size - 1; j >= 0; j--){
                dp[j] = j - stones[i] >= 0 ? max(dp[j], dp[j - stones[i]] + stones[i]) : dp[j];
            }
        }

        return sum - dp.back() * 2;
    }
};

int main(){
    vector<int> s = {31,26,33,21,40};

    Solution *a = new Solution();

    a->lastStoneWeightII(s);
    return 0;
}
