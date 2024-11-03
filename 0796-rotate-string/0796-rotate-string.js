/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
var rotateString = function(s, goal) {
    let i = 0
    while (i < s.length) {
    let first = s.substring(i)
    let next = s.substring(0,i)
    if(first+next == goal) return true
    i++
    }
    return false
};