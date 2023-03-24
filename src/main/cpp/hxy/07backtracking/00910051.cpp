/*
 * Created by hexiaoyu 
 * on 2023/3/15 23:11
 * https://leetcode.cn/problems/n-queens/
 * hard
 */
#include "vector"
#include "algorithm"
#include "string"
#include "map"

using namespace std;

class Solution {
public:

    vector<string> path;
    vector<vector<string>> res;

    /*
     * 1. 递归函数的参数和返回类型
     * @param n n阶矩阵
     * @param row 当前在第几行
     */
    void snq_bt(int n, int row){
        // 2. 出口
        if(row == n) {
            res.push_back(path);
            return;
        }

        // 3. 单层逻辑
        for(int i = 0; i < n; i++){
            if(yeahYouCanPos(n, row, i)){
                path[row][i] = 'Q';
                snq_bt(n, row + 1);
                path[row][i] = '.';
            }
            // 这里如果一行都没有任何一个位置可以插入，就会直接执行完毕return，不会进入下一个递归
        }
    }

    /*
     * n：几阶矩阵
     * row、col：要在哪插入
     */
    bool yeahYouCanPos(int n, int row, int col){
        // 行不用验证
        // 列
        for(int i = 0; i < row; i++){
            if(path[i][col] == 'Q') return false;
        }

        // 正斜
        for(int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--){
            if(path[i][j] == 'Q') return false;
        }

        //反斜
        for(int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++){
            if(path[i][j] == 'Q') return false;
        }

        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        path = vector<string>(n, string(n, '.'));
        snq_bt(n, 0);
        return res;
    }
};
