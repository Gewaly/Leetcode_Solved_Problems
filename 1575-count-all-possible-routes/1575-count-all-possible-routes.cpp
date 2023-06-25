class Solution {
public:
    const int Mod=1e9+7;
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector<vector<int>> dp(n, vector(fuel+1, -1));

        function<int(int, int, int)> dfs=[&](int i, int finish, int fuel)->int{
            if (fuel<0) return 0;
            if (dp[i][fuel]!=-1) return dp[i][fuel];
            int ans=0;
            if (i==finish) ans++;
            for(int j=0; j<n; j++){
                if (j==i) continue;
                ans=(ans+dfs(j, finish, fuel-abs(locations[i]-locations[j])))%Mod;
            }
            return  dp[i][fuel]=ans;
        };

        return dfs(start, finish, fuel);
    }
};