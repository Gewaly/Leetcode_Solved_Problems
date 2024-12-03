/**
 * @param {string} s
 * @param {number[]} spaces
 * @return {string}
 */
var addSpaces = function (s, spaces) {
    let temp = '', left = 0, right = 0, count = 0;
    while (right < s.length) {
        if (right === spaces[count]) {
            temp += s.slice(left, right) + " ";
            left = right;
            count++;
        }
        right++;
    }
    temp += s.slice(left, right);
    return temp;
    
    
    
    
    
};