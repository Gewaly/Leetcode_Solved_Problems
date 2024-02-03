class Solution {
public:
int n;
int dp[501];
int solve(int i,vector<int>& arr, int k){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int curr_max=-1;
    int ans=0;

    for(int j=i;j<n&&j-i+1<=k;j++){
        curr_max=max(curr_max,arr[j]);
        ans=max(ans,(j-i+1)*curr_max+solve(j+1,arr,k));
    }
    return dp[i]= ans;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        n=arr.size();
        return solve(0,arr,k);
    }
};