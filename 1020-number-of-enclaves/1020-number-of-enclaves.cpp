class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int count=0, m=grid.size(), n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        
        for(int i = 0;i<m;++i){
            for(int j=0;j<n;++j){
                if((i==0 || j==0 || i==m-1 || j==n-1) && grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        
        int dx[] = {-1,0,+1,0};
        int dy[] = {0,-1,0,+1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int i=0;i<4;++i){
                int nr=r+dx[i];
                int nc=c+dy[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1 && vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
               if(grid[i][j]==1 && vis[i][j]==0){
                   ++count;
               }
            }
        }
        return count;
    }
};