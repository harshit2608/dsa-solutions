const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> subs(nums.size() + 1, 0);
        for (const auto& itr : queries) {
            subs[itr[0]] -= 1;
            subs[itr[1] + 1]++;
        }

        int prefix = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += subs[i];
            nums[i] += prefix;
            if (nums[i] > 0) {
                return false;
            }
        }

        return true;
    }
};