class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int answer = 0;

        if (nums.size() <= 1) {
            return answer;
        }

        int left = 0, right = 0;
        int i = 0, j = 0;
        int oneCount = 0;

        while (i < nums.size() && j < nums.size()) {
            while (i < nums.size() && nums[i] != 0) {
                left++;
                i++;
                j++;
                oneCount++;
            }

            if (j < nums.size() && nums[j] == 0) {
                j++;
            }

            while (j < nums.size() && nums[j] != 0) {
                right++;
                j++;
                oneCount++;
            }

            answer = max(answer, left + right);
            i = j;
            left = right;
            right = 0;
        }

        if (oneCount == nums.size()) {
            return nums.size() - 1;
        }

        return answer;
    }
};