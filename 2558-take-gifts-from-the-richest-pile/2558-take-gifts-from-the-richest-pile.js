/**
 * @param {number[]} gifts
 * @param {number} k
 * @return {number}
 */
var pickGifts = function(gifts, k) {
    for(let i = 0; i < k; i++){
        gifts.sort((a,b) => a - b)
        let newEl = Math.floor(Math.sqrt(gifts.pop()))
        gifts.push(newEl)
    }
    return gifts.reduce((a,b) => a + b)
    
};
