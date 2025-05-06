const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        int minEle = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            minEle = min(minEle, prices[i]);
            answer = max(answer, prices[i] - minEle);
        }
        return answer;
    }
};