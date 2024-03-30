/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraysWithKDistinct = function (nums, k) {
    let n = nums.length;
    let m = new Array(n + 1).fill(0);
    let unique = 0;
    let Left = 0;
    let x = 0;

    let left = 0;
    for (let num of nums) {
        if (m[num] === 0) {
            unique++;
            if (unique > k) {
                m[nums[left]]--;
                unique--;
                left++;
                Left = 0;
            }
        }
        m[num]++;
        while (m[nums[left]] > 1) {
            m[nums[left]]--;
            left++;
            Left++;
        }
        if (unique === k) {
            x += Left + 1;
        }
    }
    return x;
};