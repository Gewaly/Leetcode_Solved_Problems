/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function(nums) {
    for(i in nums){
    nums[i]=nums[i]*nums[i];
    }
    nums.sort((a,b)=>a-b);
    return nums;
    
};