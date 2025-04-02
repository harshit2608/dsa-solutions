// Used iterative DFS over here instead of recursive. Idea is simple just keep marking the nodes visited.

class Solution {
private:
    bool isGridAccessible(int x, int y, int m, int n,
                          const vector<vector<char>>& grid,
                          const vector<vector<int>>& visited) {
        return (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == '1' &&
                visited[x][y] == 0);
    }

    void dfs(const vector<vector<char>>& grid, vector<vector<int>>& visited,
             int row, int col) {
        int m = grid.size();
        int n = grid[0].size();

        stack<pair<int, int>> stk;
        stk.push({row, col});
        visited[row][col] = 1;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!stk.empty()) {
            pair<int, int> top = stk.top();
            stk.pop();

            for (const pair<int, int>& dir : directions) {
                int x = top.first + dir.first;
                int y = top.second + dir.second;

                if (isGridAccessible(x, y, m, n, grid, visited)) {
                    stk.push({x, y});
                    visited[x][y] = 1;
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int m = grid.size();
        if (m == 0) {
            return 0;
        }

        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int islands = 0;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == '1' && visited[row][col] == 0) {
                    islands++;
                    dfs(grid, visited, row, col);
                }
            }
        }
        return islands;
    }
};