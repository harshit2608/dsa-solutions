const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) {
            return {};
        }

        sort(nums.begin(), nums.end());

        if (nums[0] > 0) {
            return {};
        }

        vector<vector<int>> answer;
        unordered_map<int, int> mp;
        for (int i = 0; i < len; i++) {
            mp[nums[i]] = i;
        }

        for (int i = 0; i < len - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < len - 1; j++) {
                const int reqSum = 0 - (nums[i] + nums[j]);

                if (mp.count(reqSum) && mp.find(reqSum)->second > j) {
                    answer.push_back({nums[i], nums[j], nums[mp[reqSum]]});
                }

                j = mp.find(nums[j])->second;
            }
            i = mp.find(nums[i])->second;
        }

        return answer;
    }
};