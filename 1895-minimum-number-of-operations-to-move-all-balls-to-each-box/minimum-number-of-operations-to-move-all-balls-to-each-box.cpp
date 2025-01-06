class Solution {
public:
    vector<int> minOperations(string boxes) {
        int boxSize = boxes.size();
        vector<int> answer(boxSize, 0);
        int cumVal = 0, cumSum = 0;

        for (int idx = 0; idx < boxSize; idx++) {
            answer[idx] = cumSum;
            cumVal += boxes[idx] == '0' ? 0 : 1;
            cumSum += cumVal;
        }

        cumVal = 0, cumSum = 0;
        for (int idx = boxSize - 1; idx >= 0; idx--) {
            answer[idx] += cumSum;
            cumVal += boxes[idx] == '0' ? 0 : 1;
            cumSum += cumVal;
        }

        return answer;
    }
};