class Solution {
private:
    void computeLPSArray(vector<int>& lps, const string& pattern) {
        int prefixLength = 0;
        int currentIndex = 1;

        while (currentIndex < pattern.size()) {
            if (pattern[currentIndex] == pattern[prefixLength]) {
                prefixLength++;
                lps[currentIndex] = prefixLength;
            } else {
                if (prefixLength != 0) {
                    prefixLength = lps[prefixLength - 1];
                } else {
                    lps[currentIndex] = 0;
                }
            }
            currentIndex++;
        }
    }

    bool isSubstringUsingKMP(const string& pattern, const string& text) {
        vector<int> lps(pattern.size(), 0);
        computeLPSArray(lps, pattern);

        int textIndex = 0;
        int patternIndex = 0;

        while (textIndex < text.size()) {
            if (pattern[patternIndex] == text[textIndex]) {
                textIndex++;
                patternIndex++;
            }

            if (patternIndex == pattern.size()) {
                return true;
            } else if (textIndex < text.size() &&
                       pattern[patternIndex] != text[textIndex]) {
                if (patternIndex != 0) {
                    patternIndex = lps[patternIndex - 1];
                } else {
                    textIndex++;
                }
            }
        }
        return false;
    }

public:
    vector<string> stringMatching(const vector<string>& words) {
        vector<string> result;

        for (int currentIndex = 0; currentIndex < words.size();
             currentIndex++) {
            const string& currentWord = words[currentIndex];

            for (int otherIndex = 0; otherIndex < words.size(); otherIndex++) {
                if (otherIndex == currentIndex ||
                    currentWord.size() > words[otherIndex].size()) {
                    continue;
                }

                if (isSubstringUsingKMP(currentWord, words[otherIndex])) {
                    result.push_back(currentWord);
                    break;
                }
            }
        }

        return result;
    }
};