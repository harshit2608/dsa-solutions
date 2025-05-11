const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int sz = intervals.size();

        if (sz == 1) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> answer;
        answer.push_back(intervals[0]);

        for (int i = 1; i < sz; i++) {
            if (answer.back()[1] >= intervals[i][0]) {
                answer.back()[1] = max(answer.back()[1], intervals[i][1]);
            } else {
                answer.push_back(intervals[i]);
            }
        }
        return answer;
    }
};