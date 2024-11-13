/**
 * @param {number[]} nums
 * @param {number} lower
 * @param {number} upper
 * @return {number}
 */
var countFairPairs = function(nums, lower, upper) {
    nums.sort((a, b) => a - b);
    return countLessThan(nums, upper) - countLessThan(nums, lower - 1);

    function countLessThan(nums, sum) {
        let res = 0;
        let j = nums.length - 1;
        
        for (let i = 0; i < j; ++i) {
            while (i < j && nums[i] + nums[j] > sum) {
                --j;
            }
            res += j - i;
        }
        
        return res;
    }
};