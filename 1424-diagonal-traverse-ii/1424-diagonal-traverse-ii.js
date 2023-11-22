/**
 * @param {number[][]} nums
 * @return {number[]}
 */
var findDiagonalOrder = function(nums) {
    let result = []
    let rCount = nums.length
    const map = new Map()
    for (let i = 0; i < rCount; i++) {
        for (let j = 0; j < nums[i].length; j++) {
            const check = map.get(i+j)
            if (check) {
                check.unshift(nums[i][j])
            } else {
                map.set(i+j, [nums[i][j]])
            }
        } 
    }
    for (item of map) result.push(...item[1])
    
    return result
};