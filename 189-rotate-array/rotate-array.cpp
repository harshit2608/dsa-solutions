class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        k = k % sz;
        reverse(nums, 0, sz - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, sz - 1);
    }

    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};