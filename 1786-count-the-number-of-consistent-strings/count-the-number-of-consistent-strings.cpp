class Solution {
public:
    int countConsistentStrings(string& allowed, const vector<string>& words) {
        int answer = 0;
        int allowedBit = 0;
        for (const char& ch : allowed) {
            allowedBit |= 1 << (ch - 'a');
        }

        for (const string& word : words) {
            bool isConsistent = true;
            for (const char& ch : word) {
                const int bit = allowedBit & (1 << (ch - 'a'));
                if (bit == 0) {
                    isConsistent = false;
                    break;
                }
            }

            if (isConsistent) {
                answer++;
            }
        }
        return answer;
    }
};