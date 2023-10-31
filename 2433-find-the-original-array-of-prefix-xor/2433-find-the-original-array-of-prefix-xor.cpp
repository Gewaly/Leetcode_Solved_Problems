class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
       int n = pref.size(), cur = pref[0];
        vector<int> res(n, cur);
    
        for(int i = 1; i < n; i++)
            res[i] = cur ^ pref[i], cur = pref[i];
       
        
        
        return res;
        
    }
};