/**
 * @param {string} sentence
 * @return {boolean}
 */
var isCircularSentence = function(sentence) {
      if(sentence[0]!=sentence[sentence.length-1]) return false;
    for(let i=0;i<sentence.length;i++){
        if(sentence[i]==' '&&sentence[i+1]!=sentence[i-1] )
            return false;
    }
        return true;
};