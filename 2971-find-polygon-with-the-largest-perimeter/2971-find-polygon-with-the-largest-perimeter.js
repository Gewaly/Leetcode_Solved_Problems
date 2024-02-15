/**
 * @param {number[]} nums
 * @return {number}
 */
var largestPerimeter = function(nums) {

     nums.sort((a,b)=>b-a)
    function calculateSum(nums){
     console.log(nums)
        const sum = nums.reduce((sum, curr) => sum + curr, 0);
        return sum
    }
  
    while(nums.length){
        let max = nums.shift()
        let sum = calculateSum(nums)
        console.log(sum)
        if(sum>max){
            return sum+max
        }
    }
    return -1
   
};