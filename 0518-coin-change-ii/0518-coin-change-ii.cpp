class Solution {
public:
    int change(int sum, vector<int>& coins) {
        vector<long long int> dp(sum+1, 0);
        dp[0] = 1;
        int n=coins.size();
        for(int i=0; i<n; i++)
            for(int j=coins[i]; j<=sum; j++)
                    dp[j] += dp[j-coins[i]];
        return dp[sum];
    }
};