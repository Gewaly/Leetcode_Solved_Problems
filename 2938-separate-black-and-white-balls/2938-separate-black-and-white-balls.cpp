class Solution {
public:
    long long minimumSteps(std::string s) {
        int n = s.length();
        vector<int> ones(n);
        map<int, int> mp; 
        ones[0] = (s[0] == '1') ? 1 : 0;
        
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                ones[i] = ones[i - 1] + 1;
            } else {
                ones[i] = ones[i - 1];
            }
        }

        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt += ones[i];
            }
        }
        
        return cnt;
    }
};