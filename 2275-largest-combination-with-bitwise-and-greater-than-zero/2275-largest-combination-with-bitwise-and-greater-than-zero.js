/**
 * @param {number[]} candidates
 * @return {number}
 */
var largestCombination = function(candidates) {
    let result = new Array(24).fill(0);

    for(candidate of candidates){
        candidate = candidate.toString(2).split('').reverse();
        for(let i = 0; i < candidate.length; i++){
            if(candidate[i] != '0'){
                result[i] += 1;
            }
        }
    }

    
    result.sort((a, b) => b - a);

    return result[0];
    

};
