
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var loopCheck = function(str) {
    let res = "";
    for(let i=0; i<str.length; i++) {
        if(str[i]=="#") res = res.slice(0, -1);
        else res = res + str[i];
    }
    return res;
}
var backspaceCompare = function(s, t) {
    console.log(loopCheck(s));
    console.log(loopCheck(t));
    if(loopCheck(s) == loopCheck(t)) return true;
    else return false;
};