class Solution {
private:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& matrix, int n, int r, int c) {
        if (r >= n || c >= n || c < 0) {
            return 1e4;
        }

        if (r == n - 1) {
            return matrix[r][c];
        }

        if (dp[r][c] != INT_MAX) {
            return dp[r][c];
        }

        int leftdia = solve(matrix, n, r + 1, c - 1);
        int down = solve(matrix, n, r + 1, c);
        int rightdia = solve(matrix, n, r + 1, c + 1);

        return dp[r][c] = matrix[r][c] + min({leftdia, down, rightdia});
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        dp.assign(n, vector<int>(n, INT_MAX));

        int answer = INT_MAX;
        for (int i = 0; i < n; i++) {

            answer = min(answer, solve(matrix, n, 0, i));
        }

        return answer;
    }
};