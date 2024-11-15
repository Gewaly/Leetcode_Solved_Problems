/**
 * @param {number[]} arr
 * @return {number}
 */
var findLengthOfShortestSubarray = function(arr) {
    let n = arr.length;
    let prefix = 0;
    let suffix = n - 1;

    while(prefix < n - 1) {
        if(arr[prefix] <= arr[prefix+1]) {
            prefix++;
        } else {
            break;
        }
    }

    if(prefix === n - 1) return 0;

    while(suffix > 0) {
        if(arr[suffix-1] <= arr[suffix]) {
            suffix--;
        } else {
            break;
        }
    }

    let remove = Math.min(n - 1 - prefix, suffix);
    let start = 0;
    let end = suffix;

    while(start <= prefix && end < n) {
        if(arr[start] <= arr[end]) {
            remove = Math.min(end - start - 1, remove);
            start++;
        } else {
            end++;
        }
    }

    return remove;
};