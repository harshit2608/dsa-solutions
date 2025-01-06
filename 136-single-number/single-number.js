/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function (nums) {
    let res = nums[0];
    for (let idx = 1; idx < nums.length; idx++) {
        res ^= nums[idx];
    }
    return res;
};