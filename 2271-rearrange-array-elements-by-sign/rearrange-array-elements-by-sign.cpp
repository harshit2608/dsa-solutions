const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> answer(nums.size(), 0);
        int i = 0, j = 1;
        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] >= 0) {
                answer[i] = nums[k];
                i += 2;
            } else {
                answer[j] = nums[k];
                j += 2;
            }
        }
        return answer;
    }
};