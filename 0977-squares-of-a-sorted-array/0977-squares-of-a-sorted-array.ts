function sortedSquares(nums: number[]): number[] {
    for(let i in nums){
    nums[i]=nums[i]**2;
    }
    nums.sort((a,b)=>a-b);
    return nums;
    
};