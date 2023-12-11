/**
 * @param {number[]} arr
 * @return {number}
 */
var findSpecialInteger = function(arr) {
    let count = 1;
        if (arr.length === 1) return arr[0];

    for (let i = 1; i < arr.length; i++) {
        if (arr[i] === arr[i-1]) {
            count++;
        } else {
            count = 1;
        }
        if (count > arr.length/4) return arr[i];
    }
};