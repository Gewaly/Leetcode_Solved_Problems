/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let res=0,f=0;
    for(let i=s.length-1;i>=0;i--){ 

        if(s[i].toUpperCase()!=s[i].toLowerCase()){
            for(let j=i;j>=0;j--){
                        if(s[j].toUpperCase()!=s[j].toLowerCase()) res++;
                          else{ f=1;break; }

                       if(j==0){ f=1;break; }

                

            }
                    if(f==1) break;

        }
        if(f==1) break;
    }
    return res;
    
};