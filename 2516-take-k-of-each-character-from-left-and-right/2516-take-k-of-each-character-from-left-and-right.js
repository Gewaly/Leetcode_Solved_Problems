/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
function takeCharacters(s, k) {
    const memo = {
        a: 0,
        b: 0,
        c: 0
    }

    for(let ch of s){
        memo[ch]++
    }

    if(memo.a < k || memo.b < k || memo.c < k) return -1
    
    let max = 0
    let j = 0

    for(let i = 0; i < s.length; i++){
        memo[s[i]]--

        while(memo.a < k || memo.b < k || memo.c < k){
            memo[s[j]]++
            j++
        }
        max = Math.max(max, i - j + 1)
    }
    return s.length - max
};