/**
 * @param {string} sentence
 * @param {string} searchWord
 * @return {number}
 */
var isPrefixOfWord = function(sentence, searchWord) {
    let n = sentence.length, 
        k = searchWord.length
        i = 0,
        j = 0,
        cnt = 1
    while (i < n) {
        while (i < n && sentence[i] == searchWord[j]) {
            i++
            j++
        }
        if (j == k) 
            return cnt
        while (i < n && sentence[i] != " ")
            i++
        j = 0
        cnt++
        i++
    }
    return -1
};