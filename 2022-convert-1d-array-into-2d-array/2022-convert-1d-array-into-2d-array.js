/**
 * @param {number[]} original
 * @param {number} m
 * @param {number} n
 * @return {number[][]}
 */
var construct2DArray = function(original, m, n) {
    
    if (m * n !== original.length) {
        return [];
    }
    const arr2D = [];

    for (let i = 0; i < m; i++) {
        arr2D.push(original.slice(i * n, i * n + n));
    }


    return arr2D;
};