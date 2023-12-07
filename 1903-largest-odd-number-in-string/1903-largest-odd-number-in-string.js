/**
 * @param {string} num
 * @return {string}
 */
var largestOddNumber = function(num) {


    let sub="";
     let k=num.length-1;
    for(let i=0;i<num.length;i++){
                if(parseInt(num[k])%2!=0){
                    for(i=0;i<=k;i++) sub+=num[i];
                    
                    return sub;
                } 
        else  k--;
                 
    }
    return sub;
   
};