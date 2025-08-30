class Solution {
private:
    int sol(vector<int>& dp, vector<int>& nums, int idx, bool excludeLast) {
        if (idx < 0) {
            return 0;
        }

        if (excludeLast && idx == (nums.size() - 1)) {
            return 0;
        }

        if (!excludeLast && idx == 0) {
            return 0;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int stat1 = sol(dp, nums, idx - 1, excludeLast);
        int stat2 = sol(dp, nums, idx - 2, excludeLast) + nums[idx];

        return dp[idx] = max(stat1, stat2);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1), dp2(n, -1);

        int case1 = sol(dp1, nums, n - 2, true);
        int case2 = sol(dp2, nums, n - 1, false);

        return max(case1, case2);
    }
};