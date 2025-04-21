const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
constexpr int MOD = static_cast<int>(1e9 + 7);

class Solution {
private:
    void solve(const vector<int>& candidates, int target,
               vector<vector<int>>& answer, vector<int>& temp, int idx) {
        if (target == 0) {
            answer.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (candidates[i] > target) {
                break;
            }

            temp.push_back(candidates[i]);
            solve(candidates, target - candidates[i], answer, temp, i + 1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> temp;
        solve(candidates, target, answer, temp, 0);
        return answer;
    }
};