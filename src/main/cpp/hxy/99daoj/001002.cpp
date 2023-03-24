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

class Solution{
public:
    // 确定递归函数
    void backtracking_queen1(vector<vector<int>> &ddr, int row, int &n, int &res){
        // 出口
        if(row == n) {
            backtracking_queen2(ddr, 0, n, res);
            return;
        }

        // 单层递归逻辑
        int white = 2;
        for(int col = 0; col < n; col++){
            if(ddr[row][col] == 1 and yeahYouCanPosHere(ddr, row, col, n, white)){
                ddr[row][col] = white;
                backtracking_queen1(ddr, row + 1, n, res);
                ddr[row][col] = 1;
            }
        }
    }

    void backtracking_queen2(vector<vector<int>> &ddr, int row, int &n, int &res){
        // 出口
        if(row == n) {
            res++;
            return;
        }

        // 单层递归逻辑
        int black = 3;
        for(int col = 0; col < n; col++){
            if(ddr[row][col] == 1 and yeahYouCanPosHere(ddr, row, col, n, black)){
                ddr[row][col] = black;
                backtracking_queen1(ddr, row + 1, n, res);
                ddr[row][col] = 1;
            }
        }
    }

    bool yeahYouCanPosHere(vector<vector<int>> &ddr, int row, int col, int &n, int &color){
        for(int i = 0; i < n; i++){
            if(ddr[i][col] == color) return false;
            if(ddr[row][i] == color) return false;
        }

        for(int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--){
            if(ddr[i][j] == color) return false;
        }

        for(int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++){
            if(ddr[i][j] == color) return false;
        }

        return true;
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> ddr(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> ddr[i][j];
        }
    }
    Solution *a = new Solution();
    int res = 0;
    a->backtracking_queen1(ddr, 0, n, res);
    cout << res << endl;
    return res;
}