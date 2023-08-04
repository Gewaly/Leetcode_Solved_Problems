class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
          unordered_map<string,int>mp;
    for(auto word:wordDict) mp[word]++;
    
    int n=s.size();
   vector<bool> dp(n+1);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && mp.count(s.substr(j,i-j))){
                    dp[i]=true;
                }
            }
        }
        return dp[n];
    }
};