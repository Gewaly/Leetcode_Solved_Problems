class Solution {
public:
    int numTilings(int n) {
         int MOD = 1e9 + 7;
	vector<long> dp = { 0, 1, 2, 5 };
	dp.resize (n+1);

	for (int i = 4; i <= n; i++) {
		dp[i]  = 2 * dp[i - 1] + dp[i - 3];
		dp[i] %= MOD;
	}

	return dp[n];
        
    }
};