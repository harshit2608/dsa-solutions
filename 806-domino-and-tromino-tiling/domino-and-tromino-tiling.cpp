const auto _ = cin.tie(nullptr)->sync_with_stdio(false);
constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int numTilings(int n) {
        vector<vector<int>> dp(3, vector<int>(2));
        dp[1] = {1, 1}, dp[2] = {2, 2};
        for (int i = 3; i <= n; i++) {
            dp[i % 3][0] = (dp[(i - 1) % 3][0] + dp[(i - 2) % 3][0] +
                            2l * dp[(i - 2) % 3][1]) %
                           MOD;
            dp[i % 3][1] = (dp[(i - 1) % 3][0] + dp[(i - 1) % 3][1]) % MOD;
        }
        return dp[n % 3][0];
    }
};