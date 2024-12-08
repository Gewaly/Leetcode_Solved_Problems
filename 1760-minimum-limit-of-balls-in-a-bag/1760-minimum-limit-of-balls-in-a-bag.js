/**
 * @param {number[]} nums
 * @param {number} maxOperations
 * @return {number}
 */
var minimumSize = function(nums, maxOperations) {
    let lower = 0,  high = Math.max(...nums);
    while (lower < high) {
        const medValue = Math.floor((lower + high) / 2);
        if (isValid(nums, maxOperations, medValue)) {
            high = medValue;
        } else {
            lower = medValue + 1;
        }
    }
    return lower;
};

function isValid(nums, maxOperations, maxVal) {
    let totalNumOperations = 0;
    for (const num of nums) {
        const numberOfOperations = Math.ceil(num / maxVal) - 1;
        totalNumOperations += numberOfOperations;
    }
    return totalNumOperations <= maxOperations;
}
