class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = nums[0];
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
            prod = max(prod, max(prefix, suffix));
        }
        return prod;
    }
};