const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
private:
    int solve(int steps, vector<int>& dp) {
        if (steps == 0) {
            return 1;
        }
        if (steps < 0) {
            return 0;
        }

        if (dp[steps] != -1) {
            return dp[steps];
        }
        return dp[steps] = solve(steps - 1, dp) + solve(steps - 2, dp);
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int step = 2; step <= n; step++) {
            dp[step] = dp[step - 1] + dp[step - 2];
        }
        return dp[n];
    }
};
