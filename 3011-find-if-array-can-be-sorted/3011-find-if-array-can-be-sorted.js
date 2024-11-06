/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canSortArray = function (nums) {
     function setBits (num) {
        let count = 0;
        for (let i = 31; i >= 0; i--) {
            if (((num >> i) & 1) === 1) {
                count++;
            }
        }
        return count;
    };

     function check (nums) {
        for (var i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    };

    let count = [];
    for (let j = 0; j < nums.length; j++) {
        count[j] = setBits(nums[j]);
    }

    let n = nums.length;
    let k = 0;
    while (k < n) {
        for (var i = 1; i < n; i++) {
            if (count[i] === count[i - 1] && nums[i] < nums[i - 1]) {
                var temp = nums[i];
                nums[i] = nums[i - 1];
                nums[i - 1] = temp;
            }
        }
        if (check(nums)) {
            return true;
        }
        k++;
    }
    return false;
};