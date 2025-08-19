class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long subarrays = 0;

        long long contCount = 0;
        for (const int& num : nums) {
            if (num == 0) {
                contCount++;
            } else {
                contCount = 0;
            }
            subarrays += contCount;
        }

        return subarrays;
    }
};
