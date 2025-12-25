function maximumHappinessSum(happiness: number[], k: number): number {
  happiness.sort(function(a, b){return b-a});
        let n=happiness.length,res=0;
     for(let i=0;i<n;i++){
            if(k==0) return res;
            if((happiness[i]-i)<0) res=res+0;
            else res=res+(happiness[i]-i);
            k--;
        }
        return res;
};