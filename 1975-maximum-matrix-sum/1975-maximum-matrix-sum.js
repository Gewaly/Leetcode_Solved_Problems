/**
 * @param {number[][]} matrix
 * @return {number}
 */
var maxMatrixSum = function (matrix) {
    let res = 0, bad = 0, min = Infinity;
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            res += Math.abs(matrix[i][j]);
            if (matrix[i][j] < 0) bad++;
            min = Math.min(min, Math.abs(matrix[i][j]))
        }
    }
    if (bad % 2 === 1) res -= min * 2;
    return res;
};