class Solution {
public:
    typedef vector<vector<int>> vii;
    void solve(vii &g1, vii &g2, int i, int j,bool &issame){
        if(i>=0 && j>=0 && i<g2.size() && j<g2[0].size() && g2[i][j] == 1){
            if(g1[i][j] != g2[i][j]) issame = false;
            g2[i][j] = 0;
            solve(g1,g2,i,j+1,issame);
            solve(g1,g2,i,j-1,issame);
            solve(g1,g2,i+1,j,issame);
            solve(g1,g2,i-1,j,issame);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0;
        for(int i=0;i<grid1.size();i++){
            for(int j=0;j<grid1[0].size();j++){
                if(grid2[i][j] == 1){
                    bool issame=true;
                    solve(grid1,grid2,i,j,issame);
                    if(issame) ans++;
                    issame = true;
                }
            }
        }
        return ans;
    }
};