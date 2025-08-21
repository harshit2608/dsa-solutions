class Solution {
private:
    int sol(const vector<int>& sol) {
        int run = 0, res = 0;
        for (const int x : sol) {
            run = (x == 1) ? run + 1 : 0;
            res += run;
        }
        return res;
    }

public:
    int numSubmat(vector<vector<int>>& mat) {
        int result = 0;
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++) {
            vector<int> hist(n, 1);

            for (int j = i; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    hist[k] &= mat[j][k];
                }

                result += sol(hist);
            }
        }
        return result;
    }
};