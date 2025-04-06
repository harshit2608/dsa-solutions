const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
private:
    int recursion(vector<int>& dp, int n) {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        if (dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = recursion(dp, n - 1) + recursion(dp, n - 2);
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return recursion(dp, n);
    }
};