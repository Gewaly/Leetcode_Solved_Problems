class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
    unordered_map<char, int> mp;
    int maxi = -1;
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (mp.find(c) != mp.end())   maxi = max(maxi, i - mp[c] - 1);
        else  mp[c] = i;
        
    }
    return maxi;
    }
};