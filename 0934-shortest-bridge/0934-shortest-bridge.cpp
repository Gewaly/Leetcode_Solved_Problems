class Solution {
public:
    queue<pair<int,int>>q;
    int visited[101][101];
    void dfs(int i,int j,queue<pair<int,int>>&q,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=grid.size()|| j>=grid.size() || visited[i][j])  return;
        visited[i][j]=true;
        if(grid[i][j]==0){q.push({i,j});
        return;}
        dfs(i+1,j,q,grid);
        dfs(i-1,j,q,grid);
        dfs(i,j+1,q,grid);
        dfs(i,j-1,q,grid);

    }
    int shortestBridge(vector<vector<int>>& grid) {
        memset(visited,0,sizeof(visited));
        int n=grid.size();
        int m=grid[0].size();
        int flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)     
                {
                    flag =1;
                    dfs(i,j,q,grid);
                    break;
                }
            }
            if(flag)break;
        }
        int level=0;
        vector<int>rowDir = {-1,1,0,0};
        vector<int>colDir = {0,0,-1,1};
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {   
                int curRow = q.front().first;
                int curCol = q.front().second;
                if(grid[curRow][curCol]==1)return level;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nextRow= curRow+rowDir[i];
                    int nextCol= curCol+colDir[i];
                    if(nextRow>=0 && nextCol>=0 &&nextCol<n && nextRow<n && !visited[nextRow][nextCol])
                    {
                        visited[nextRow][nextCol]=1;
                        q.push({nextRow,nextCol});
                    }
                }
                
            }
            level++;
        }
        return level;
    }
};