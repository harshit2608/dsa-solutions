class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        unordered_map<int, int> ngeIndex;
        stack<int> ms;

        for (const auto& i : nums2) {
            while (!ms.empty() && (i > ms.top())) {
                ngeIndex[ms.top()] = i;
                ms.pop();
            }
            ms.push(i);
        }
        while (!ms.empty()) {
            ngeIndex[ms.top()] = -1;
            ms.pop();
        }
        for (const auto& i : nums1) {
            answer.push_back(ngeIndex[i]);
        }
        return answer;
    }
};