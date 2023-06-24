class Solution {
public:
    int helper(int index,int sum,vector<int>&rods,vector<vector<int>>&dp){
        int n= rods.size();
        if(index>=n){
            if(sum==5000) return 0;
            return INT_MIN;
        }
        if(dp[index][sum]!=INT_MIN) return dp[index][sum];
        int option1= helper(index+1,sum,rods,dp);
        int option2= helper(index+1, sum-rods[index],rods,dp);
        int option3= rods[index]+helper(index+1,sum+rods[index],rods,dp);
        return dp[index][sum]=max({option1,option2,option3});
    }
    int tallestBillboard(vector<int>& rods) {
        int n= rods.size();
        vector<vector<int>>dp(n,vector<int>(10001,INT_MIN));
        return helper(0,5000,rods,dp);
        
    }
};