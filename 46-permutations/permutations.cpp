const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
private:
    vector<vector<int>> answer;
    void solve(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            answer.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            solve(nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, 0);
        return answer;
    }
};