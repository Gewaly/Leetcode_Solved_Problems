function maxProduct(nums: number[]): number {
    nums.sort(function(a, b){return b-a});
            return (nums[0]-1)*(nums[1]-1);


    
};