/**
 * @param {number[][]} matrix
 * @return {number}
 */
var maxEqualRowsAfterFlips = function(matrix) {
    d = {}
    for (let row of matrix) {
        h = row[0]? row.join("") : row.map(x => 1 - x).join("")
        d[h] = (d[h] || 0) + 1
    }
    return Math.max(...Object.values(d))
};