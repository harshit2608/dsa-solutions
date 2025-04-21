    const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
    constexpr int MOD = static_cast<int>(1e9 + 7);

    class Solution {
    private:
        vector<vector<int>> answer;
        void solve(vector<int>& candidates, vector<int>& temp, int target,
                int idx) {
            if (target == 0) {
                answer.push_back(temp);
                return;
            }

            if (idx >= candidates.size()) {
                return;
            }

            // take
            if (target >= candidates[idx]) {
                temp.push_back(candidates[idx]);
                solve(candidates, temp, target - candidates[idx], idx);
                temp.pop_back();
            }

            // not take
            solve(candidates, temp, target, idx + 1);
        }

    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int> temp;
            solve(candidates, temp, target, 0);
            return answer;
        }
    };