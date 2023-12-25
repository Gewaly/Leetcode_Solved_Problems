class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int dp0 = 0, dp1 = 1;
        for (int i = 0; i < n; i++) {
            int dp2 = 0;
            if (('1' <= s[i]) && (s[i] <= '9')) dp2 += dp1;
            if (i >= 1) {
                if (s[i - 1] == '1') dp2 += dp0;
                if ((s[i - 1] == '2') && ('0' <= s[i]) && (s[i] <= '6')) dp2 += dp0;
            }
            dp0 = dp1;
            dp1 = dp2;
        }
        return dp1;
    }
};