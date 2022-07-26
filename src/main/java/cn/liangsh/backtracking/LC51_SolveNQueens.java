package cn.liangsh.backtracking;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author Liangsh
 * @description N皇后
 * @date 2022/7/25 9:43
 */
public class LC51_SolveNQueens {

    List<List<String>> result = new ArrayList<>();

    public static void main(String[] args) {
        System.out.println(new LC51_SolveNQueens().solveNQueens(4));
    }

    public List<List<String>> solveNQueens(int n) {

        // 设置N行N列的棋盘
        char[][] chessboard = new char[n][n];
        for (char[] chars : chessboard) {
            Arrays.fill(chars, '.');
        }

        //          列数    行数   棋盘
        backtracking(n, 0, chessboard);

        return result;
    }

    private void backtracking(int n, int row, char[][] chessboard) {
        if (row == n) {
//            result.add(Arrays.stream(chessboard).map(Arrays::toString).collect(Collectors.toList()));
            result.add(ArraysToList(chessboard));
            return;
        }

        for (int col = 0; col < n; col++) {
            // 判断当前棋盘位置是否可用
            if (validQueens(row, col, n, chessboard)) {
                chessboard[row][col] = 'Q';
                // 继续判断下一行
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.';
            }
        }

    }

    private List<String> ArraysToList(char[][] chessboard) {
        List<String> list= new ArrayList<>();

        for (char[] chars : chessboard) {
            list.add(String.copyValueOf(chars));
        }
        return list;
    }

    private boolean validQueens(int row, int col, int n, char[][] chessboard) {
        // 判断同列
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }

        // 判断45°角
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }

        // 判断135°角
        for (int i = row - 1, j = col + 1; i >= 0 && j <= n - 1; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }

        }

        return true;
    }
}
