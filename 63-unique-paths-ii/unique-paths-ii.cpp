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
        
        if (obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        dp.assign(m, vector<int>(n, -1));
        return solve(obstacleGrid, m, n, 0, 0);
    }
};