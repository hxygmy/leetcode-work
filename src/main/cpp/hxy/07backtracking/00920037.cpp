/*
 * Created by hexiaoyu 
 * on 2023/3/16 0:29
 * https://leetcode.cn/problems/sudoku-solver/
 * hard
 */
#include "vector"

using namespace std;

class Solution {

    bool ssk_bt(vector<vector<char>> &board){

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    for(char k = '1'; k <= '9'; k++){
                        if(yeahYouCanPos(board, i, j, k)){
                            board[i][j] = k;
                            if(ssk_bt(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool yeahYouCanPos(vector<vector<char>> &board, int row, int col, char num){

        // 行列
        for(int i = 0; i < 9; i++){
            if(board[row][i] == num) return false;
            if(board[i][col] == num) return false;
        }

        // 九宫格
        for(int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++){
            for(int j = (col / 3) * 3; j < (col / 3) * 3 + 3; j++){
                if(board[i][j] == num) return false;
            }
        }

        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        ssk_bt(board);
    }
};
