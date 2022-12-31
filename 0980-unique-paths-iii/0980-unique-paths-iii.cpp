class Solution {
public:
      int ans;
    void findAll(vector<vector<int>> &grid,vector<vector<bool>> &vis,int i,int j,int cnt){
        
        if(i>=grid.size()||i<0 || j>=grid[0].size() || j<0 || vis[i][j] || grid[i][j]==-1){
            return;
        }
        
        if(grid[i][j]==2 && cnt==0){
            ans++;
        }
        
        vis[i][j]=1;
        cnt--;
        
        findAll(grid,vis,i+1,j,cnt);
        findAll(grid,vis,i-1,j,cnt);
        findAll(grid,vis,i,j+1,cnt);
        findAll(grid,vis,i,j-1,cnt);
        
        vis[i][j]=0;
        cnt++;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),0));
        int ii,jj;
        int cnt=0;
        ans=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0 ){
                    cnt++;
                }
                if(grid[i][j]==1){
                    ii=i;
                    jj=j;
                    cnt++;
                }
            }
        }
        
        findAll(grid,vis,ii,jj,cnt);
        
        return ans;
    }
};