const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        for (const int& itr : nums) {
            if (count == 0) {
                count++;
                candidate = itr;
            } else if (candidate == itr) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};