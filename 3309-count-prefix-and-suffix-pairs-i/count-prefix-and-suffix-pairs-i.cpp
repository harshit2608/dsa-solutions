class Solution {
private:
    bool isPrefix(const string& word1, const string& word2) {
        if (word1.size() > word2.size())
            return false;

        for (int i = 0; i < word1.size(); i++) {
            if (word1[i] != word2[i]) {
                return false;
            }
        }
        return true;
    }

    bool isSuffix(const string& word1, const string& word2) {
        if (word1.size() > word2.size())
            return false;

        int word1Index = word1.size() - 1;
        int word2Index = word2.size() - 1;

        while (word1Index >= 0) {
            if (word1[word1Index] != word2[word2Index]) {
                return false;
            }
            word1Index--;
            word2Index--;
        }
        return true;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int answer = 0;

        for (int i = 0; i < words.size(); i++) {
            const string& word = words[i];
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefix(word, words[j]) && isSuffix(word, words[j])) {
                    answer++;
                }
            }
        }
        return answer;
    }
};