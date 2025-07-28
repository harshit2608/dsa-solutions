class Solution {
private:
    int calcOR(const vector<int>& subset) {
        int res = 0;
        for (const int& it : subset) {
            res |= it;
        }
        return res;
    }

    vector<vector<int>> answer;

    void solve(const vector<int>& nums, int idx, vector<int>& temp) {
        if (idx == nums.size()) {
            answer.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(nums, idx + 1, temp);

        temp.pop_back();
        solve(nums, idx + 1, temp);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums, 0, temp);

        unordered_map<int, int> mp;

        for (const auto& itr : answer) {
            int res = calcOR(itr);
            mp[res]++;
        }

        int res = 0;
        for (const auto& it : mp) {
            res = max(res, it.second);
        }
        return res;
    }
};