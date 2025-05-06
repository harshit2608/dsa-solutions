const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = nums.size() - 2;
        while (idx >= 0 && nums[idx] >= nums[idx + 1]) {
            idx--;
        }

        if (idx < 0) {
            sort(nums.begin(), nums.end());
            return;
        }

        int swapIdx = nums.size() - 1;
        while (swapIdx > idx && nums[swapIdx] <= nums[idx]) {
            swapIdx--;
        }

        swap(nums[idx], nums[swapIdx]);
        sort(nums.begin() + idx + 1, nums.end());
    }
};