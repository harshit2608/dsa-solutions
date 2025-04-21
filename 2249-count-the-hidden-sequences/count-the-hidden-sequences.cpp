const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
constexpr int MOD = static_cast<int>(1e9 + 7);

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long sum = 0;
        long long mini = 0, maxi = 0;

        for (const int& diff : differences) {
            sum += diff;
            mini = min(mini, sum);
            maxi = max(maxi, sum);
        }

        long long minAlpha = static_cast<long long>(lower) - mini;
        long long maxAlpha = static_cast<long long>(upper) - maxi;

        return static_cast<int>(max(0LL, maxAlpha - minAlpha + 1));
    }
};