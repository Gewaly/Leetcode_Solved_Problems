/**
 * @param {number} n
 * @return {number}
 */
var numberOfMatches = function(n) {

    let count = 0;
    while(n>1){
        count = count + Math.floor(n/2);
        n = Math.ceil(n/2)
        
    }

    return count
    
};