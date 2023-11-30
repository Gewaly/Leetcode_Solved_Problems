/**
 * @param {number} n
 * @return {number}
 */
var minimumOneBitOperations = function (n) {
  let b = Math.log2(n + 1) | 0;
  while (b) n ^= ((n >> b) & 1) << (--b);
  return n;
};