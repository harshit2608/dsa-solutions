class Solution {
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& og, int m, int n, int right, int down) {
        if (m - 1 == right && n - 1 == down) {
            return 1;
        }

        if (right >= m || down >= n) {
            return 0;
        }

        if (og[right][down] == 1) {
            return 0;
        }

        if (dp[right][down] != -1) {
            return dp[right][down];
        }

        return dp[right][down] = solve(og, m, n, right + 1, down) +
                                 solve(og, m, n, right, down + 1);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) {
            return 0;
        }

        dp.assign(m + 1, vector<int>(n + 1, 0));
        dp[1][1] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1)
                    continue;
                if (obstacleGrid[i - 1][j - 1] == 1) {
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m][n];
    }
};