class Solution {
public:
    int solve(int i,int j,int n,int m,string &s1,string &s2,vector<vector<int>> &dp){
        if(i>=n && j>=m) return 0;
        if(i==n){
            int sum=0;
            while(j<m){
                sum+=s2[j];
                j++;
            }
            return sum;
        }
        if(j==m){
            int sum=0;
            while(i<n){
                sum+=s1[i];
                i++;
            }
            return sum;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) dp[i][j]= 0 + solve(i+1,j+1,n,m,s1,s2,dp);
        else dp[i][j]= min(s1[i]+solve(i+1,j,n,m,s1,s2,dp),s2[j]+solve(i,j+1,n,m,s1,s2,dp));
        return dp[i][j];
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,s1,s2,dp);
    }
};