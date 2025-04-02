class Solution {
public:
    long long maximumTripletValue(const vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        if (n < 3) {
            return 0;
        }

        long long ans = 0;
        vector<int> leftMax(n, 0), rightMax(n, 0);

        leftMax[0] = nums[0];
        for (int idx = 1; idx < n; idx++) {
            leftMax[idx] = max(leftMax[idx - 1], nums[idx]);
        }

        rightMax[n - 1] = nums[n - 1];
        for (int idx = n - 2; idx >= 0; idx--) {
            rightMax[idx] = max(rightMax[idx + 1], nums[idx]);
        }

        for (int idx = 1; idx < n - 1; idx++) {
            ans = max(ans, (long long)(leftMax[idx - 1] - nums[idx]) *
                               rightMax[idx + 1]);
        }

        return ans;
    }
};