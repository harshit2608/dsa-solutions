
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int answer = 0;
        unordered_set<int> st;

        for (const int& itr : nums) {
            st.insert(itr);
        }

        const int uniqueEle = st.size();
        st.clear();

        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> subSet;
            for (int j = i; j < nums.size(); j++) {
                subSet.insert(nums[j]);
                if (subSet.size() == uniqueEle) {
                    answer++;
                }
            }
        }

        return answer;
    }
};