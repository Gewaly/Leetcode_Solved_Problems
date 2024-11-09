/**
 * @param {number} n
 * @param {number} x
 * @return {number}
 */
var minEnd = function(n, x) {
    n--;
    let a = n.toString(2).split('').map(Number).reverse();
    let b = x.toString(2).split('').map(Number).reverse();
    let r = Array(60).fill(0);
    for (let i = 0; i < b.length; i++) {
        r[i] = b[i];
    }
    let p = 0;
    for (let i = 0; i < a.length; i++) {
        while (r[p]) p++;
        r[p++] = a[i];
    }
    let res = 0, temp = 1;
    for (let i = 0; i < r.length; i++) {
        if (r[i]) res += temp;
        temp *= 2;
    }
    return res;
};