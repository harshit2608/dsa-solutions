class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int sz = grid.size();
        if (grid.empty()) {
            return {};
        }

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                mp[i - j].push_back(grid[i][j]);
            }
        }

        for (auto& entry : mp) {
            if (entry.first >= 0)
                sort(entry.second.begin(), entry.second.end());
            else
                sort(entry.second.rbegin(), entry.second.rend());
        }

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                grid[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }

        return grid;
    }
};