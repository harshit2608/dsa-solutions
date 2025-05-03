class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0, answer = 0;

        mp[0] = 1;
        // in prefix sum its-> [...(x-k),..x]
        // if toatl is x and from end some is k remaining is x-k

        for (const int& itr : nums) {
            sum += itr;
            answer += mp[sum - k];
            mp[sum]++;
        }

        return answer;
    }
};