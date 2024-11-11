/**
 * @param {number[]} nums
 * @return {boolean}
 */
var primeSubOperation = function(nums) {
    let res = true;
    for(let i=nums.length-1; i>=1; i--){
        if(nums[i] <= nums[i-1]){
            let rest = nums[i-1] - nums[i] + 1;
            let flag = false;
            while(rest < nums[i-1]){
                if(check(rest) && nums[i-1] - rest > 0){
                    flag = true;
                    nums[i-1] = nums[i-1] - rest;
                    break;
                }else{
                    rest ++;
                }
            }
            if(!flag){
                res = false;
                break;
            }
        }
    }
    return res;
};

function check(num){
    if (num <= 3) {
        return num > 1;
    }
    if (num % 6 != 1 && num % 6 != 5) {
        return false;
    }
    let sqrt = Math.sqrt(num);
    for (let i = 5; i <= sqrt; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}