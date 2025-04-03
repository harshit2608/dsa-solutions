class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> answer(n, 0);
        for (int i = 0; i < n; i++) {
            answer[i] = nums[i] * nums[i];
        }

        sort(answer.begin(), answer.end());
        return answer;
    }
};