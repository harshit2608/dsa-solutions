const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
private:
    vector<vector<int>> answer;
    void solve(vector<int>& nums, vector<int>& temp, vector<bool>& freq) {
        if (temp.size() == nums.size()) {
            answer.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                freq[i] = true;
                temp.push_back(nums[i]);
                solve(nums, temp, freq);
                temp.pop_back();
                freq[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<bool> freq(nums.size(), false);
        solve(nums, temp, freq);
        return answer;
    }
};