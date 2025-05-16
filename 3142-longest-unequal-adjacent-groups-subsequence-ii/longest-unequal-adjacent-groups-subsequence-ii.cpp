class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = words.size();
        vector<int> memo(n, -1);
        vector<int> nextIndex(n, -1);
        int maxLen = 0, start = 0;

        for (int i = 0; i < n; ++i) {
            int len = dfs(i, words, groups, memo, nextIndex);
            if (len > maxLen) {
                maxLen = len;
                start = i;
            }
        }

        // Reconstruct result
        vector<string> answer;
        while (start != -1) {
            answer.push_back(words[start]);
            start = nextIndex[start];
        }
        return answer;
    }

private:
    int dfs(int i, vector<string>& words, vector<int>& groups,
            vector<int>& memo, vector<int>& nextIndex) {
        if (memo[i] != -1)
            return memo[i];

        int maxLen = 1;
        int bestNext = -1;

        for (int j = i + 1; j < words.size(); ++j) {
            if (groups[i] != groups[j] && words[i].size() == words[j].size() &&
                differByOne(words[i], words[j])) {

                int currLen = 1 + dfs(j, words, groups, memo, nextIndex);
                if (currLen > maxLen) {
                    maxLen = currLen;
                    bestNext = j;
                }
            }
        }

        memo[i] = maxLen;
        nextIndex[i] = bestNext;
        return maxLen;
    }

    bool differByOne(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                if (++diff > 1)
                    return false;
            }
        }
        return diff == 1;
    }
};