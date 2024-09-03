/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var getLucky = function(s, k) {
    let res=0;
        let ss=""; 
        
        for(let i=0;i<s.length;i++){
           let n = s.charCodeAt(i) - 'a'.charCodeAt(0) + 1;
           let g = n.toString();
           ss += g;
        }
       while(k--){
           res=0;
        for(let i=0;i<ss.length;i++){
        res+=ss[i]-'0';
            
        }
        
       ss=res.toString();
       }
        
        return res; 
        
       
    
};