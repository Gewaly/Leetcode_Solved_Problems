/**
 * @param {number[]} piles
 * @return {number}
 */
var maxCoins = function(piles) {
    piles.sort((a, b) => a - b);
    let times = piles.length / 3, result = 0 , index = piles.length - 2;
    while(times > 0){
        result += piles[index];
        index-=2;
        times--;
    }
    
    return result;
};