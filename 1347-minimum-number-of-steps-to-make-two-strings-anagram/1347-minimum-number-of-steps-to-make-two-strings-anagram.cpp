class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mps;
        unordered_map<char, int> mpt;
        int res = 0;
        
        for (int i = 0; i < s.size(); i++) {
            mps[s[i]]++;
            mpt[t[i]]++; 
        }
        
        for (auto it = mps.begin(); it != mps.end(); it++) {
            auto i = mpt.find(it->first);
            if (i != mpt.end()) {
                if (it->second - i->second > 0)    res = res + (it->second - i->second);
                
            } else 
                res = res + it->second;
            
        }
        
        return res;
    }
};
