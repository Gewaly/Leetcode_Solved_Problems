/**
 * @param {string} str1
 * @param {string} str2
 * @return {boolean}
 */

var canMakeSubsequence = function(str1, str2) {
    let a = 0, b = 0;
    if (str1.length < str2.length) return false;
    
    while(b < str2.length) {
        if (str1.charCodeAt(a) == str2.charCodeAt(b) || (str1.charCodeAt(a)+1-97)%26 == (str2.charCodeAt(b)-97)%26) {
            a++;
            b++;
        } else {
            a++;
        }
        if (b < str2.length && a >= str1.length) return false;
    }
    return true;
};