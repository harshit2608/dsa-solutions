const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
private:
    vector<vector<string>> answer;
    bool isValidLocation(int col, int row, vector<string>& board) {
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void solve(int n, vector<string>& board, int row) {
        if (row == n) {
            answer.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValidLocation(col, row, board)) {
                board[row][col] = 'Q';
                solve(n, board, row + 1);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(n, board, 0);
        return answer;
    }
};