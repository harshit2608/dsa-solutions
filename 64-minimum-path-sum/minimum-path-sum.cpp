class Solution {
private:
    int solve(vector<vector<int>>& grid, int m, int n) {
        if (m < 0 || n < 0) {
            return INT_MAX;
        }

        if (m == 0 && n == 0) {
            return grid[m][n];
        }

        return min(solve(grid, m - 1, n), solve(grid, m, n - 1)) + grid[m][n];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};