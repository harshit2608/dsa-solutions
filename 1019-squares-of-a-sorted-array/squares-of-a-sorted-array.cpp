const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 0);
        int i = 0, j = n - 1;
        int k = n - 1;

        while (i <= j) {
            int sq1 = nums[i] * nums[i];
            int sq2 = nums[j] * nums[j];

            if (sq1 > sq2) {
                answer[k--] = sq1;
                i++;
            } else {
                answer[k--] = sq2;
                j--;
            }
        }
        return answer;
    }
};
