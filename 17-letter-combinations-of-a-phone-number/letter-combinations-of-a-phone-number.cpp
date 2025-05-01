class Solution {
private:
    vector<string> store = {"",    "",    "abc",  "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;

    void solve(const string& digits, string& temp, int idx) {
        if (temp.size() == digits.size()) {
            ans.push_back(temp);
            return;
        }

        const int digit = digits[idx] - '0';
        for (int i = 0; i < store[digit].size(); i++) {
            temp += store[digit][i];
            solve(digits, temp, idx + 1);
            temp.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0 || digits == "") {
            return {};
        }

        string temp;
        solve(digits, temp, 0);
        return ans;
    }
};