class Solution {
public:
    int m;
    int cut(int i,int j, vector<int>& cuts,vector<vector<int>>&dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int curr_cost = INT_MAX;
        for(int k=i+1;k<=j-1;k++){
            int total = cut(i,k,cuts,dp) + cut(k,j,cuts,dp) + (cuts[j]-cuts[i]);
            curr_cost = min(curr_cost,total);
        }
        return dp[i][j] = (curr_cost==INT_MAX) ? 0: curr_cost ;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        m = cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        sort(cuts.begin(),cuts.end());
        return cut(0,m-1,cuts,dp);
    }
};