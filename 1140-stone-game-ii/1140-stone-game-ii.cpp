class Solution {
public:
    int n;
    int dp[105][105];
    int dfs(vector<int>&p, int i,int m)
    {
        if(i==n) return 0;
        if(dp[i][m]!=-1) return dp[i][m];
        int ans=INT_MIN,sum=0;
        for(int j=i;j<n && j-i+1<=2*m;j++)
        {
            sum+=p[j];
            ans=max(ans,sum-dfs(p,j+1,max(m,j-i+1)));
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        int sum= accumulate(piles.begin(),piles.end(),0);
        //cout<<sum<<" "<<dfs(piles,0,1);
        return (sum+dfs(piles,0,1))/2;
    }
};