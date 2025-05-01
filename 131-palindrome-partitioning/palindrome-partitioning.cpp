const auto _ = cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
private:
    vector<vector<string>> answer;
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

    void solve(const string& str, vector<string>& path, int idx) {
        if (idx == str.size()) {
            answer.push_back(path);
            return;
        }

        for (int i = idx; i < str.size(); i++) {
            if (isPalindrome(str, idx, i)) {
                path.push_back(str.substr(idx, i - idx + 1));
                solve(str, path, i + 1);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        solve(s, path, 0);
        return answer;
    }
};