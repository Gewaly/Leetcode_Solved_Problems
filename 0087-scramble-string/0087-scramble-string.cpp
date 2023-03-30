class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length(); // Get the length of the strings
        if (n != s2.length()) { // If the lengths are not equal, return false
            return false;
        }
        bool dp[n + 1][n][n]; // Define a 3D boolean array to store the results
        memset(dp, false, sizeof(dp)); // Initialize all values to false
        for (int i = 0; i < n; i++) { // Base case: length 1
            for (int j = 0; j < n; j++) {
                if (s1[i] == s2[j]) { // If the characters are equal, set dp[1][i][j] to true
                    dp[1][i][j] = true;
                }
            }
        }
        for (int l = 2; l <= n; l++) { // General case: length > 1
            for (int i = 0; i <= n - l; i++) {
                for (int j = 0; j <= n - l; j++) {
                    for (int k = 1; k < l; k++) { // Divide the strings into two substrings at all possible positions
                        if ((dp[k][i][j] && dp[l - k][i + k][j + k]) || // Check if the two substrings are scrambled strings of each other in swapped order
                            (dp[k][i][j + l - k] && dp[l - k][i + k][j])) { // Check if the two substrings are scrambled strings of each other in same order
                            dp[l][i][j] = true; // If any one of these checks returns true, set dp[l][i][j] to true
                            break;
                        }
                    }
                }
            }
        }
        return dp[n][0][0]; // Return dp[n][0][0], which is the final result
    }
};