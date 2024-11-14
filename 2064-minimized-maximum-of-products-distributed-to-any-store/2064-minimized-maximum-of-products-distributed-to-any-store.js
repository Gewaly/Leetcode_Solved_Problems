/**
 * @param {number} n
 * @param {number[]} quantities
 * @return {number}
 */
var minimizedMaximum = function (n, quantities) {
  if (n == quantities.length) {
    return Math.max(...quantities);
  }

  let l = 0;
  let h = Math.max(...quantities);

  while (l < h) {
    const mid = Math.floor((l + h) / 2);
    const y = canDistribute(mid, quantities, n);

    if (y) {
      h = mid;
    } else {
      l = mid + 1;
    }
  }

  return l;
};

function canDistribute(avg, quantities, n) {
  let stores = n;

  for (let num of quantities) {
    const q = Math.floor(num / avg);
    const r = num % avg > 0 ? 1 : 0;;

    stores -= q + r;

    if (stores < 0) {
      return false;
    }
  }

  return true
}