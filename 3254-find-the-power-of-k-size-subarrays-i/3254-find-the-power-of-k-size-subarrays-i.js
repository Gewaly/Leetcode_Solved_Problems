/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var resultsArray = function(nums, k) {
    let n = nums.length;
    let ans = new Array(n - k + 1).fill(-1); 
    let i = 0, j = 0;
    
    while (j < n) {
        if (j > 0 && nums[j] - nums[j - 1] !== 1) {
            i = j;
        }

  
        while (i < j && j - i + 1 > k) {
            i++;
        }

        if (j - i + 1 === k) {
            ans[j - k + 1] = nums[j];
        }
        
        j++;
    }

    return ans;
};