/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
        t=t.split("").sort().join("");
        s=s.split("").sort().join("");
    console.log(s," ",t);
        if(s==t) return true;
        return false;
    
};