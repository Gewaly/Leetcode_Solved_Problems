/**
 * @param {number} low
 * @param {number} high
 * @return {number[]}
 */
var sequentialDigits = function(low, high) {
    let str = "123456789";
    let lowest = low.toString().length;
    let highest = high.toString().length;
    let res = [];
    for(let i=lowest; i<=highest; i++) {
        let a = 9-i;
        for(let x=0; x<=a; x++) {
            let sub = parseInt(str.substring(x, i+x));
            if(low<=sub && sub<=high)res.push(sub);
        }
    }
    return res;
}