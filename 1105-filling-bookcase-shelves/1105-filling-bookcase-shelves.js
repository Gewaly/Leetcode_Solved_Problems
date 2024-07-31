/**
 * @param {number[][]} books
 * @param {number} shelfWidth
 * @return {number}
 */
let n, WIDTH, memo;
const solve = (books, i, remainW, maxHt) => {
    if (i >= n) return maxHt;

    if (memo[i][remainW] !== 0) return memo[i][remainW]

    const bookW = books[i][0];
    const bookH = books[i][1];

    let keep = Infinity
    let skip = Infinity

    if (bookW <= remainW) {
        keep = solve(books, i + 1, remainW - bookW, Math.max(maxHt, bookH))
    }

    skip = maxHt + solve(books, i + 1, WIDTH - bookW, bookH)

    memo[i][remainW] = Math.min(keep, skip)
    return memo[i][remainW]
}

var minHeightShelves = function (books, shelfWidth) {
    n = books.length;
    WIDTH = shelfWidth;
    memo = Array.from ({length:n}, ()=> Array(WIDTH + 1).fill(0))
    return solve(books, 0, shelfWidth, 0)
};