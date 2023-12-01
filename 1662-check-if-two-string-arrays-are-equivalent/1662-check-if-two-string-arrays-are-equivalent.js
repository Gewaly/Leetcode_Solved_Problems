/**
 * @param {string[]} word1
 * @param {string[]} word2
 * @return {boolean}
 */
var arrayStringsAreEqual = function(word1, word2) {
      let res1="";
        for(let i=0;i<word1.length;i++)
            res1+=word1[i];
        
         let res2="";
        for(let i=0;i<word2.length;i++)
            res2+=word2[i];
        
        
        return res2==res1;
    
};