/*
 * Created by hexiaoyu 
 * on 2023/3/24 19:56
 * 2n皇后问题
 * Description
 * 给定一个n*n的棋盘，棋盘中有一些位置不能放皇后。
 * 现在要向棋盘中放入n个黑皇后和n个白皇后，
 * 使任意的两个黑皇后都不在同一行、同一列或同一条对角线上，
 * 任意的两个白皇后都不在同一行、同一列或同一条对角线上。问总共有多少种放法？n小于等于8。
 * Input
 * 输入的第一行为一个整数n，表示棋盘的大小。
 * 接下来n行，每行n个0或1的整数，如果一个整数为1，表示对应的位置可以放皇后，
 * 如果一个整数为0，表示对应的位置不可以放皇后。
 * Output
 * 输出一个整数，表示总共有多少种放法。
 **/

#include "iostream"
#include "vector"

using namespace std;

int main(){
    int n;
    cin >> n;
    int t;
    vector<vector<int>> ddr(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> t;
            ddr[i][j] = t;
        }
    }
    int res;
}

// 确定递归函数
void backtracking_queen1(vector<vector<int>> &ddr, int row, int &n, int &res){
    // 出口
    if(row == n) return;
    bool yeahYouCanPosHere(vector<vector<int>> &ddr, int row, int col, int &n);
    // 单层递归逻辑
    for(int col = 0; col < n; col++){
        if(yeahYouCanPosHere(ddr, row, col, n)){

        }
    }
}

bool yeahYouCanPosHere(vector<vector<int>> &ddr, int row, int col, int &n){
    return false;
}