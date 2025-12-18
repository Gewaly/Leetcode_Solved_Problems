class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long baseProfit = 0;

        vector<long long> A(n), B(n);
        for (int i = 0; i < n; i++) {
            A[i] = 1LL * strategy[i] * prices[i];
            B[i] = prices[i] - A[i];
            baseProfit += A[i];
        }

        vector<long long> prefA(n + 1, 0), prefB(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefA[i + 1] = prefA[i] + A[i];
            prefB[i + 1] = prefB[i] + B[i];
        }

        int mid = k / 2;
        long long bestDelta = 0;

        for (int l = 0; l + k <= n; l++) {
            long long firstHalf = prefA[l + mid] - prefA[l];
            long long secondHalf = prefB[l + k] - prefB[l + mid];
            long long delta = -firstHalf + secondHalf;
            bestDelta = max(bestDelta, delta);
        }

        return baseProfit + bestDelta;
    }
};