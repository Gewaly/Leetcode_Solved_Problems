class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
       for (int R = n - 2; R >= 0; --R) {
        for (int C = 0; C < n; ++C) {
 
            int best = matrix[R + 1][C];
            if (C > 0)
                best = min(best, matrix[R + 1][C - 1]);
            if (C + 1 < n)
                best = min(best, matrix[R + 1][C + 1]);
            matrix[R][C] = matrix[R][C] + best;
        }
    }
 
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i)
        ans = min(ans, matrix[0][i]);
    return ans;
    }
};