class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1;
        while (j < nums.size()) {
            if(nums[j]==nums[j-1]){
                j++;
                continue;
            }

            nums[i] = nums[j];
            i++;
            j++;
        }
        return i;
    }
};