class Solution {
private:
    const double EPS = 0.1;
    bool solve(vector<double>& cards) {
        if (cards.size() == 1) {
            return abs(cards[0] - 24) <= EPS;
        }

        for (int i = 0; i < cards.size(); i++) {
            for (int j = 0; j < cards.size(); j++) {
                if (i == j) {
                    continue;
                }

                vector<double> temp;
                for (int k = 0; k < cards.size(); k++) {
                    if (k != i && k != j) {
                        temp.push_back(cards[k]);
                    }
                }

                const double a = cards[i];
                const double b = cards[j];
                vector<double> poss = {a + b, a - b, a * b,
                                       b - a, a / b, b / a};

                for (const double& itr : poss) {
                    temp.push_back(itr);
                    if (solve(temp)) {
                        return true;
                    }
                    temp.pop_back();
                }
            }
        }
        return false;
    }

public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
};