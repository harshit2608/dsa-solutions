class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> answer;
        int sz = nums.size();
        sort(nums.begin(), nums.end());

        int count = 1;
        for (int i = 1; i < sz; i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                if (count > sz / 3) {
                    answer.push_back(nums[i - 1]);
                }
                count = 1;
            }
        }

        if (count > sz / 3) {
            answer.push_back(nums[sz - 1]);
        }
        return answer;
    }
};