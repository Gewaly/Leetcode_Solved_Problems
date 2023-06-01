class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        if(grid[0][0] != 0)
            return -1;
        q.push({{0,0},1});
        while(q.size() != 0)
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            if(row == n-1 && col==m-1)
                return steps;
            vis[row][col] = 1;
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int nrow = row+i;
                    int ncol = col+j;
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol]
                      && grid[nrow][ncol] == 0)
                    {
                        if(nrow == n-1 && ncol==m-1)
                            return steps+1;
                        vis[nrow][ncol] = 1;
                        q.push({{nrow,ncol},steps+1});
                    }
                }
            }
        }
        return -1;
        
    }
};