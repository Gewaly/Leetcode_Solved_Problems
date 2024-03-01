/**
 * @param {string} s
 * @return {string}
 */
const maximumOddBinaryNumber = (s) => {
    const onesCount = (s.match(/1/g) || []).length;
    const zerosCount = s.length - onesCount;
    return "1".repeat(onesCount - 1) + "0".repeat(zerosCount) + "1";
};