class Solution {
public:
    
    vector<vector<int>> dp;
    
    int f(string&s, int low, int high, vector<string>&dictionary){
        int &ans = dp[low][high];
        if(ans!=-1) return ans;
        ans = high-low;
        
        string tok = s.substr(low, high-low);
        for(auto&d:dictionary){
            int id = tok.find(d);
            if(id==-1) continue;
            ans = min(ans, f(s,low,low+id,dictionary) + f(s,low+id+d.size(),high,dictionary));
        }
        return ans;
        
    }
    
    
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
    
        dp.assign(n+1, vector<int>(n+1,-1));
        
        f(s,0,n,dictionary);
        return dp[0][n];
    }
};