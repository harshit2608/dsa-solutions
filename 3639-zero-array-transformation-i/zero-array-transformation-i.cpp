const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> subs(nums.size() + 1, 0);
        for (const auto& itr : queries) {
            subs[itr[0]] += -1;
            subs[itr[1] + 1] += 1;
        }

        for (int i = 1; i < subs.size(); i++) {
            subs[i] += subs[i - 1];
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] += subs[i];
        }

        for (const int& itr : nums) {
            if (itr > 0) {
                return false;
            }
        }
        return true;
    }
};