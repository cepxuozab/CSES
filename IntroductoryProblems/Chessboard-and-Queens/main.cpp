#include <iostream>
#include <vector>

using namespace std;

auto isSafe(vector<string> &board, int row, int col) -> bool {
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); --i, ++j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void solveQueens(vector<string> &board, int row, int &count) {
    if (row == board.size()) {
        ++count;
        return;
    }

    for (int col = 0; col < board.size(); ++col) {
        if (board[row][col] == '.' && isSafe(board, row, col)) {
            board[row][col] = 'Q';
            solveQueens(board, row + 1, count);
            board[row][col] = '.';
        }
    }
}

auto main() -> int {
    vector<string> board(8);
    for (int i = 0; i < 8; ++i) {
        cin >> board[i];
    }
    int count = 0;
    solveQueens(board, 0, count);
    cout << count << '\n';
    return 0;
}