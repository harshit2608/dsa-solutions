class Solution {
public:
    int minTimeToVisitAllPoints(const vector<vector<int>>& points) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        // The key idea: Move diagonally as much as possible.
        // Since a diagonal move reduces both x and y by 1 simultaneously,
        // the minimum of (x difference, y difference) represents the diagonal
        // steps. The remaining steps (after exhausting diagonals) are purely
        // horizontal/vertical. Thus, max(|x2 - x1|, |y2 - y1|) directly gives
        // the total time required.
        int answer = 0;
        for (int idx = 1; idx < points.size(); idx++) {
            answer += max(abs(points[idx][0] - points[idx - 1][0]),
                          abs(points[idx][1] - points[idx - 1][1]));
        }
        return answer;
    }
};