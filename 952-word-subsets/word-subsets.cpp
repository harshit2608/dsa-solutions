class Solution {
public:
    vector<string> wordSubsets(const vector<string>& words1,
                               const vector<string>& words2) {
        vector<string> answer;
        vector<int> maxFreq(26, 0);

        for (const string& word : words2) {
            vector<int> freq(26, 0);
            for (const char& ch : word) {
                freq[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        for (const string& word : words1) {
            vector<int> freq(26, 0);
            for (const char& ch : word) {
                freq[ch - 'a']++;
            }

            bool isUniversal = true;
            for (int idx = 0; idx < 26; idx++) {
                if (freq[idx] < maxFreq[idx]) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) {
                answer.push_back(word);
            }
        }

        return answer;
    }
};