class Solution {
public:
    int m, n;
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis){
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j]==true || grid[i][j]==0) return;

        vis[i][j] = true;


        dfs(grid, i+1, j, vis);
        dfs(grid, i-1, j, vis);
        dfs(grid, i, j+1, vis);
        dfs(grid, i, j-1, vis);

    }
    int countNoOfIslandUtil(vector<vector<int>>& grid){
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int island = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && vis[i][j]==false){
                    island++;
                    dfs(grid, i, j, vis);
                }
            }
        }

        return island;
    }
    int minDays(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int islands = countNoOfIslandUtil(grid);

        if(islands>1 || islands==0) return 0;

        else {
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(grid[i][j]==1){
                        grid[i][j] = 0;
                        int noOfIsland = countNoOfIslandUtil(grid);
                        if(noOfIsland>1 || noOfIsland==0) return 1;
                        grid[i][j]=1; 
                    }
                }
            }
        }

        return 2;
        
    }
};