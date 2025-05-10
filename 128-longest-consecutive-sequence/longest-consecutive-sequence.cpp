const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> freq(nums.begin(), nums.end());

        int answer = 0;
        for (const auto& itr : freq) {
            if (!freq.count(itr - 1)) {
                int len = 1;
                int num = itr;

                while (freq.count(num + 1)) {
                    len++;
                    num++;
                }

                answer = max(answer, len);
            }
        }

        return answer;
    }
};