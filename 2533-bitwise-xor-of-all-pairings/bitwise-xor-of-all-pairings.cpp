class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int, long> map;

        for (const int& num : nums1) {
            map[num] += m;
        }

        for (const int& num : nums2) {
            map[num] += n;
        }

        int res = 0;
        for (const auto& itr : map) {
            const int key = itr.first;
            const long freq = itr.second;
            if (freq % 2 != 0) {
                res ^= key;
            }
        }
        return res;
    }
};