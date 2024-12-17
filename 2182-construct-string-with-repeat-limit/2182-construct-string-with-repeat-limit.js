/**
 * @param {string} s
 * @param {number} repeatLimit
 * @return {string}
 */
var repeatLimitedString = function (s, repeatLimit) {
    let arr = Array.from(Array(26), () => 0);

    for (let i = 0; i < s.length; i++) {
        arr[s.charCodeAt(i) - 97]++;
    }

    let i = 25;
    let j = 24;
    let string = "";
    let repeat = 0;
    while (j >= 0 && i >= 0) {
        if (repeat == repeatLimit) {
            if (i != j && arr[j] != 0) {
                string += String.fromCharCode(j + 97);
                arr[j]--;
                repeat = 0;
            } else j--;
        }
        if (arr[i] > 0 && repeat < repeatLimit) {
            string += String.fromCharCode(i + 97);
            arr[i]--;
            repeat++;
        }

        if (arr[i] == 0) {
            i--;
            repeat = 0;
        }
    }

    return string;
};