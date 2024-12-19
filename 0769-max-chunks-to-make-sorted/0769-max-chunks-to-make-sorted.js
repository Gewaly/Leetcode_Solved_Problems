/**
 * @param {number[]} arr
 * @return {number}
 */
var maxChunksToSorted = function(arr) {
  let maxValue = 0 , count = 0;
  for(let i =0; i<arr.length;i++ ){
    maxValue = Math.max(maxValue, arr[i]);
    if(maxValue === i){
        count++;
    }

    }
 return count;
};