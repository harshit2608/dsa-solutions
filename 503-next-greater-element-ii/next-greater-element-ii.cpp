const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, -1);
        stack<int> store;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!store.empty() && nums[i % n] >= store.top()) {
                store.pop();
            }
            if (!store.empty()) {
                answer[i % n] = store.top();
            }
            store.push(nums[i % n]);
        }

        return answer;
    }
};