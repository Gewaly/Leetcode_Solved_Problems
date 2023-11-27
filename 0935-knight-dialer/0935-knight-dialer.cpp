class Solution {
public:

    vector<vector<int>> arr,dir;
    int dp[10][10][5005];
    int mod = 1000000007;

    int helper(int i, int j, int n){
        if(n==1) return 1;

        if(dp[i][j][n]!=-1) return dp[i][j][n];

        int ans = 0;
        for(int k=0; k<8; k++){
            int nr = i+dir[k][0];
            int nc = j+dir[k][1];

            if(nr>=0 && nc>=0 && nr<4 && nc<3 && arr[nr][nc]!=-1){
                ans = ans + helper(nr,nc,n-1);
                ans = ans%mod;
            }
        }
        return dp[i][j][n] = ans%mod;
    }
    int knightDialer(int n) {
        arr = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        dir = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};

        memset(dp,-1,sizeof dp);

        int ans = 0;
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                if(arr[i][j]!=-1) ans = ans + helper(i,j,n); ans = ans%mod;
            }
        }
        return ans;
    }
};