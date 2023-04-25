/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    var ans=0;
    while(x!=0){
         ans=parseInt(ans*10+x%10);
        console.log(ans); 
        x=parseInt(x/10);
        if(Math.abs(ans)>2147483647) return 0;
    }
    return ans;
    
};