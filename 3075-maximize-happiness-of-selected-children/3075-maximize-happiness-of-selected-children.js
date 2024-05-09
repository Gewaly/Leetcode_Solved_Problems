/**
 * @param {number[]} happiness
 * @param {number} k
 * @return {number}
 */
var maximumHappinessSum = function(happiness, k) {
    let n=happiness.length,res=0;
    happiness.sort((a,b)=>b-a);
    for(let i=0;i<n;i++){
        if(k==0) return res;
        if((happiness[i]-i)<0) res+=0;
        else res=res+(happiness[i]-i);
        k--;
    }
    return res;
    
};