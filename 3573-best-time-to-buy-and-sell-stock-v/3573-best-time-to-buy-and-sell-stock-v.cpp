class Solution {
public:
long long solve(int i,int j,int k,vector<int> &p,vector<vector<vector<long long>>> &dp)
{
    if(i>=p.size()) return j==0? 0 : INT_MIN;
    if(k<=0) return 0;
    if(dp[i][k][j]!=-1) return dp[i][k][j];
    long long tk=0;
    if(j==0 && k>0)
    {
        tk=max(-p[i]+solve(i+1,1,k,p,dp),p[i]+solve(i+1,2,k,p,dp));
    }
    else if(j==1 && k>0)
    {
    tk=p[i]+solve(i+1,0,k-1,p,dp);
    }
    else if(j==2 && k>0)  
    {
        tk=-p[i]+solve(i+1,0,k-1,p,dp);
    }
    long long ntk=solve(i+1,j,k,p,dp);
    return dp[i][k][j]=max(tk,ntk);

}
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<long long >>> dp(n,(vector<vector<long long>> (k+1,vector<long long>(3,-1))));  
        return solve(0,0,k,prices,dp);
    }
};