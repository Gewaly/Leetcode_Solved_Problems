/**
 * @param {number[]} target
 * @param {number[]} arr
 * @return {boolean}
 */
var canBeEqual = function(target, arr) {
    target.sort((a,b)=>a-b);
    arr.sort((a,b)=>a-b);
    return JSON.stringify(arr)==JSON.stringify(target);

};