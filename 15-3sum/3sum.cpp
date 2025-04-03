const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return {};
        }

        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                if (total > 0) {
                    right--;
                } else if (total < 0) {
                    left++;
                } else {
                    answer.push_back({nums[i], nums[left], nums[right]});
                    left++;

                    while (nums[left] == nums[left - 1] && left < right) {
                        left++;
                    }
                }
            }
        }

        return answer;
    }
};