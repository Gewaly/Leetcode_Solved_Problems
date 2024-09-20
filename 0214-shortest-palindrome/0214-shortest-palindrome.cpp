class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int j = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == s[j]){
                j++;
            }
        }
        if(j==n) return s;
        string suffix = s.substr(j);
        string prefix = string(suffix.rbegin(), suffix.rend());

        return prefix + shortestPalindrome(s.substr(0,j)) + suffix;
    }
};