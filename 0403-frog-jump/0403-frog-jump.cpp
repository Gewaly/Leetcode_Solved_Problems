class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        
        vector<vector<int>>dp(n, vector<int>(n, false));
        dp[0][1] = true;
        
        for (int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int d = stones[i] - stones[j];
                if (d > 0 && d < n && dp[j][d]) {
                    if (i == n-1) return true;
                    dp[i][d] = true;
                    if (d+1 < n) dp[i][d+1] = true;
                    if (d-1 < n) dp[i][d-1] = true;
                }
            }
        }
        
        return false;
    }
};