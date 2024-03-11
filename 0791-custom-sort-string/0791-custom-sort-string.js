/**
 * @param {string} order
 * @param {string} s
 * @return {string}
 */
const customSortString = (S, T) =>
  T.split('')
    .sort((a, b) => S.indexOf(a) - S.indexOf(b))
    .join('');