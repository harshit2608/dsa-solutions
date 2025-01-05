class Solution {
public:
    bool checkPerfectNumber(int num) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (num <= 0) {
            return false;
        }

        int sum = 0;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (num / i != i) {
                    sum += num / i;
                }
            }
        }

        return sum - num == num;
    }
};