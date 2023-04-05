/**
 * @param {number[]} nums
 * @return {number}
 */
var minimizeArrayValue = function(nums) {
     let total=nums[0],res=nums[0];
        for(let i=1;i<nums.length;i++){
            total+=nums[i];
            res=Math.max(res,(Math.ceil(total/(i+1))) );
        }
        return res;
};