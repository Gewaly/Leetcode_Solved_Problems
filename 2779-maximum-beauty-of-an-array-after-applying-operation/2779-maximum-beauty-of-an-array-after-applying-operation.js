/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumBeauty = function(nums, k) {
   let map = new Map()
   for(const num of nums){
    const start = num - k
    const end = num + k + 1

    map.set(start,(map.get(start) || 0) + 1)
    map.set(end,(map.get(end) || 0) - 1)
   }

   let currentFrequency = 0
   let maxBeauty = 0

   const keys = [...map.keys()].sort((a,b) => a-b)
   for(const key of keys){
    currentFrequency += map.get(key)
    maxBeauty = Math.max(maxBeauty, currentFrequency)
   }

   return maxBeauty
};