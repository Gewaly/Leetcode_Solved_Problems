/**
 * @param {number} n
 * @return {number}
 */
var pivotInteger = function(n) {
      if(n==1) return 1;
        let j=1,res=0,ans;
        for(let i=n;i>=1;i--) {   
            res+=i;
           ans=n-j;
            if(ans*(ans+1)/2==res+ans ) { return ans; } 
         j++;
            
        }
    return -1;
};