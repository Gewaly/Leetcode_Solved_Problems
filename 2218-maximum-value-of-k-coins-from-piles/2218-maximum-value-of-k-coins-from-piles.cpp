class Solution {
    #define ll long long
public:
    int c(vector<vector<int>>& p,int i,int k,vector<vector<int>>&dp){
        if(k==0)return 0;
        if(i>=p.size())return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int ans=0;
        int mx=c(p,i+1,k,dp);
        for(int j=0;j<p[i].size();j++){
            ans += p[i][j];
            if(k>=j+1)
           mx = max(mx,ans+c(p,i+1,k-j-1,dp));
           else break;
        }
        dp[i][k]=mx;
        return mx;
    }
    int maxValueOfCoins(vector<vector<int>>& p, int k) {
        int n=p.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return c(p,0,k,dp);
    }
};