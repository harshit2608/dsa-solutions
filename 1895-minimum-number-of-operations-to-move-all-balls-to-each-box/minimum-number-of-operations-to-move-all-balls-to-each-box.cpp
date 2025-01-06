class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> results;
        int answer = 0;
        
        for (int i = 0; i < boxes.size(); i++) {
            for (int j = 0; j < boxes.size(); j++) {
                if (boxes[j] == '1') {
                    answer += abs(j - i);
                }
            }
            results.push_back(answer);
            answer = 0;
        }

        return results;
    }
};