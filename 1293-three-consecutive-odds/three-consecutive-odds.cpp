class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int consecutiveCount = 0;
        for (const int& itr : arr) {
            if (itr % 2 == 1) {
                consecutiveCount++;
            } else {
                consecutiveCount = 0;
            }
            if (consecutiveCount == 3) {
                return true;
            }
        }

        return false;
    }
};