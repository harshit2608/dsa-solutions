const auto _ = cin.tie(nullptr)->sync_with_stdio(false);
class Solution {
private:
    vector<string> answer;
    void solve(string& path, int n, int open, int close) {
        if (path.size() == 2 * n) {
            answer.push_back(path);
            return;
        }

        if (open < n) {
            path += '(';
            solve(path, n, open + 1, close);
            path.pop_back();
        }
        if (close < open) {
            path += ')';
            solve(path, n, open, close + 1);
            path.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string path;
        solve(path, n, 0, 0);
        return answer;
    }
};