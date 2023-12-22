/**
 * @param {string} s
 * @return {number}
 */
var maxScore = function(s) {
    
    let noOfOnes=s.split('1').length-1,noOfzeros=0, maxScor=0

    if(!noOfOnes) return s.length-1

    for(let i=0;i<s.length-1 ;i++){
        if(s[i]=='0'){
            noOfzeros++ 
        }else{
            noOfOnes--
        }
        maxScor=Math.max(maxScor,noOfzeros+noOfOnes)
    }
    return maxScor
};