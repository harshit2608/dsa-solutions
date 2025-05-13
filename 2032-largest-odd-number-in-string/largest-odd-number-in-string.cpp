const auto _ = cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    string largestOddNumber(string num) {
        int sz = num.size();
        if ((num[sz - 1] - '0') % 2 != 0) {
            return num;
        }

        string answer = "";

        int idx = -1;
        for (int i = 0; i < sz; i++) {
            if ((num[i] - '0') % 2 != 0) {
                idx = i;
            }
        }

        if (idx >= 0) {
            answer = num.substr(0, idx + 1);
        }
        return answer;
    }
};