const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
private:
    vector<vector<int>> answer;

    void solve(const vector<int>& nums, int idx, vector<int>& temp) {
        if (idx == nums.size()) {
            answer.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(nums, idx + 1, temp);

        temp.pop_back();
        solve(nums, idx + 1, temp);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums, 0, temp);
        return answer;
    }
};