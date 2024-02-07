#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<char>> &board) {
    // Check row
    for (int j = 0; j < col; j++) {
        if (board[row][j] == 'Q') {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check bottom left diagonal
    for (int i = row, j = col; i < board.size() && j >= 0; i++, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void printSolution(vector<vector<char>> &board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(vector<vector<char>> &board, int col, int n) {
    // Base case
    if (col >= n) {
        printSolution(board, n);
        cout << endl;
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board)) {
            board[row][col] = 'Q';
            solve(board, col + 1, n);
            board[row][col] = '-'; // Backtrack
        }
    }
}

int main() {
    // N-Queens problem
    // '-' -> empty cell
    // 'Q' -> Queen at the cell

    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    int col = 0;

    solve(board, col, n);

    return 0;
}
