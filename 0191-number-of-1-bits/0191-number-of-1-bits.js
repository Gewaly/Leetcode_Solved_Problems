/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    let res=0;
    while(n>0){
        res+=n%2;
        n=Math.floor(n/2);
    }
    return res;
};