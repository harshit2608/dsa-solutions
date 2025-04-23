const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
private:
    int calcSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int maxi = 0;

        for (int i = 1; i <= n; i++) {
            const int sum = calcSum(i);
            maxi = max(maxi, ++mp[sum]);
        }

        int answer = 0;
        for (const auto& itr : mp) {
            if (itr.second == maxi) {
                answer++;
            }
        }

        return answer;
    }
};