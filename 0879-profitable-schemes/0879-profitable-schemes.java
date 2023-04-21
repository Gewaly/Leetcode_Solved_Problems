class Solution {
    long mod=(long)1e9+7;
    public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
        long dp[][][]=new long[group.length][n+1][minProfit+1];
        for(long p[][]:dp){
            for(long x[]:p)Arrays.fill(x,-1);
        }
        return (int)f(0,n,group,profit,minProfit,dp);
    }
    public long f(int i,int n,int gr[],int pr[],int mprofit,long dp[][][]){
        if(i>=gr.length){
            if(mprofit==0)return 1;
            return 0;
        }
        if(dp[i][n][mprofit]!=-1)return dp[i][n][mprofit];
        long take=0;
        if(n>=gr[i]){
            take=f(i+1,n-gr[i],gr,pr,Math.max(mprofit-pr[i],0),dp);
        }
        long not=f(i+1,n,gr,pr,mprofit,dp);
        return dp[i][n][mprofit]=((take%mod+not%mod)%mod);
    }
}