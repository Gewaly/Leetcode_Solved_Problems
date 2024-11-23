/**
 * @param {character[][]} box
 * @return {character[][]}
 */
var rotateTheBox = function (box) {
    const m = box.length;
    const n = box[0].length;
    const result = Array.from({ length: n }, () => Array(m).fill('.'));

    for (let i = 0; i < m; i++) {
        let lowestRowWithEmptyCell = n - 1;
        for (let j = n - 1; j > -1; j--) {
            if (box[i][j] === '#') {
                result[lowestRowWithEmptyCell][m - i - 1] = '#';
                lowestRowWithEmptyCell--;
            }
            if (box[i][j] === '*') {
                result[j][m - i - 1] = '*';
                lowestRowWithEmptyCell = j - 1;
            }
        }
    }
    return result;
};