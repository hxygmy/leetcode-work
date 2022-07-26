package cn.liangsh.backtracking;

/**
 * @author Liangsh
 * @description 解数独
 * @date 2022/7/26 8:56
 */
public class LC37_SolveSudoku {

    public void solveSudoku(char[][] board) {

        backTracking(board);
    }

    private boolean backTracking(char[][] board) {

        // 行
        for (int i = 0; i < board.length; i++) {
            // 列
            for (int j = 0; j < board[0].length; j++) {
                // 1-9
                if (board[i][j] != '.') {
                    continue;
                }
                for (char k = '1'; k <= '9'; k++) {
                    if (isValid(i, j, k, board)) {
                        board[i][j] = k;
                        if (backTracking(board)) {
                            return true;
                        }
                        // 回溯
                        board[i][j] = '.';
                    }

                }
                // 9宫格内不能填满数字
                return false;
            }

        }
        return true;
    }

    private boolean isValid(int row, int col, char k, char[][] board) {
        // 判断行是否符合规则
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == k) {
                return false;
            }
        }

        // 判断列是否符合规则
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == k) {
                return false;
            }
        }

        // 判断3 x 3宫格内是否重复
        // 找出宫格起始位置
        int r = (row / 3) * 3;
        int c = (col / 3) * 3;

        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                if (board[i][j] == k) {
                    return false;
                }
            }
        }

        return true;
    }
}
