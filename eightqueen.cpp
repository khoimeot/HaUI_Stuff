#include <iostream>
#include <vector>
using namespace std;

const int N = 8;

bool isSafe(int row, int col, vector<vector<int>>& board) {
    // Kiểm tra cột
    for (int i = 0; i < row; i++) {
        if (board[i][col]) return false;
    }
    // Kiểm tra đường chéo trái
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }
    // Kiểm tra đường chéo phải
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) return false;
    }
    return true;
}

void solveNQueens(int row, vector<vector<int>>& board) {
    if (row == N) {
        for (const auto& row : board) {
            for (int cell : row) {
                cout << (cell ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col, board)) {
            board[row][col] = 1;
            solveNQueens(row + 1, board);
            board[row][col] = 0; // Backtrack
        }
    }
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, 0));
    solveNQueens(0, board);
    return 0;
}
