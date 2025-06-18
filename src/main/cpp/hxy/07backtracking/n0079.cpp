#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(std::vector<std::vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && bt(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool bt(std::vector<vector<char>> &board, string &word, int p, int row, int line) {
        if (board[row][line] == word[p]) {
            if (p == word.length() - 1) return true;
            board[row][line] = '0';
            if (row > 0 && bt(board, word, p + 1, row - 1, line)) {
                return true;
            }
            if (line > 0 && bt(board, word, p + 1, row, line - 1)) {
                return true;
            }
            if (row < board.size() - 1 && bt(board, word, p + 1, row + 1, line)) {
                return true;
            }
            if (line < board[0].size() - 1 && bt(board, word, p + 1, row, line + 1)) {
                return true;
            }
            board[row][line] = word[p];
        }

        return false;
  }
};
int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    vector<vector<char>> board1 = {
        {'a'}
    };
    auto *s = new Solution();
    auto c = s->exist(board, "ABCB");
    cout << c << endl;
    return 0;
}