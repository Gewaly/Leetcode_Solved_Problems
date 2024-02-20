/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    nums.sort(function(a,b){ return a-b;});
    let i;
    for(i=0;i<nums.length;i++){
        if(i!=nums[i]) return i;
    }
    return i;
    
};