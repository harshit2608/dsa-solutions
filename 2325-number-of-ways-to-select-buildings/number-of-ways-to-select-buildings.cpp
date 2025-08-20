class Solution {
public:
    long long numberOfWays(string s) {
        long long n = s.size();
        long long ones = 0, zeros = 0;
        for (char c : s)
            (c == '1' ? ones : zeros)++;

        long long left1 = 0, left0 = 0;
        long long ans = 0;

        for (char c : s) {
            if (c == '1') {
                ones--;
                ans += left0 * zeros;
                left1++;
            } else {
                zeros--;
                ans += left1 * ones;
                left0++;
            }
        }
        return ans;
    }
};