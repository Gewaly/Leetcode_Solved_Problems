class Solution {
public:
    long long mostPoints(vector<vector<int>>& v) {
        int n = v.size();
        long long ans = LLONG_MIN;
        vector<long long> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            long long p = 0;
            if(i + v[i][1] + 1 <= n){
                p = dp[i + v[i][1] + 1];
            }
            dp[i] = max(p + v[i][0], dp[i+1]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};