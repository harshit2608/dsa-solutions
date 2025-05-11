const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int answer = INT_MIN;
        int sz = nums.size();

        int prefix = 1, suffix = 1;
        for (int i = 0; i < sz; i++) {
            if (prefix == 0) {
                prefix = 1;
            }
            if (suffix == 0) {
                suffix = 1;
            }

            prefix *= nums[i];
            suffix *= nums[sz - i - 1];

            answer = max(answer, max(prefix, suffix));
        }

        return answer;
    }
};