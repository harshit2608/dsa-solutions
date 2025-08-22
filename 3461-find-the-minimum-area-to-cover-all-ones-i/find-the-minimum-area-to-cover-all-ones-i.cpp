class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int startRow = m, endRow = -1;
        int startCol = n, endCol = -1;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    startRow = min(startRow, row);
                    startCol = min(startCol, col);
                    endRow = max(endRow, row);
                    endCol = max(endCol, col);
                }
            }
        }

        return (endRow - startRow + 1) * (endCol - startCol + 1);
    }
};