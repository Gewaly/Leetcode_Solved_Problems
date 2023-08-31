class Solution {
public:
    int minTaps(int n, vector<int>& r) {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            int left = max(0, i - r[i]);
            int right = min(i + r[i], n);
            for (int j = left; j <= right; j++) {
                dp[j] = min(dp[j], dp[left] + 1);
            }
        }
        if(dp[n] == n+1) return -1;
        return dp[n];
    }
};