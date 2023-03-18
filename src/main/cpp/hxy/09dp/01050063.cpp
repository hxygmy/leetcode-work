/*
 * Created by hexiaoyu 
 * on 2023/3/18 19:18
 * https://leetcode.cn/problems/unique-paths-ii/
 * medium
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        // 1.dp数组的含义
        // 2. 递推式
        // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

        // 3.初始化
        int i;
        for(i = 1; i < obstacleGrid[0].size(); i++){
            if(obstacleGrid[0][i] == 0) {
                obstacleGrid[0][i] = 1;
            } else {
                break;
            }
        }
        while(i < obstacleGrid[0].size()){
            obstacleGrid[0][i++] = 0;
        }

        for(i = 1; i < obstacleGrid.size(); i++){
            if(obstacleGrid[i][0] == 0) {
                obstacleGrid[i][0] = 1;
            } else {
                break;
            }
        }
        while(i < obstacleGrid.size()){
            obstacleGrid[i++][0] = 0;
        }
        obstacleGrid[0][0] = 1;

        // 4. 递推顺序
        // 5. 举例
        for(i = 1; i < obstacleGrid.size(); i++){
            for(int j = 1; j < obstacleGrid[0].size(); j++){
                obstacleGrid[i][j] = obstacleGrid[i][j] == 1 ? 0 : obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
        }

        return obstacleGrid.back().back();
    }
};
