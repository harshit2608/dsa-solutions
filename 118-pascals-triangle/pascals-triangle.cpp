const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        answer.push_back({1});

        if (numRows == 1) {
            return answer;
        }

        answer.push_back({1, 1});
        for (int i = 3; i <= numRows; i++) {
            vector<int> row(i, 1);
            for (int j = 1; j < i - 1; j++) {
                row[j] = answer.back()[j - 1] + answer.back()[j];
            }
            answer.push_back(row);
        }
        return answer;
    }
};