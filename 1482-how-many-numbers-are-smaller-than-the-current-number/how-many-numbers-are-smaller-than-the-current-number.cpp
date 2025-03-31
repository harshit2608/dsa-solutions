class Solution {
public:
    vector<int> smallerNumbersThanCurrent(const vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> ans(nums.begin(), nums.end());
        sort(ans.begin(), ans.end());

        unordered_map<int, int> mp;
        for (int i = ans.size() - 1; i >= 0; i--) {
            mp[ans[i]] = i; // Representing how many numbers are smaller
        }

        for (int i = 0; i < nums.size(); i++) {
            ans[i] = mp[nums[i]];
        }

        return ans;
    }
};
