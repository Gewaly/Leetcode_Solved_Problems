class Solution {
public:
    int dp[31][31][65];

    int getShoretestPathfromSrctoDest(vector<string> grid, int sr,int sc,int er,int ec, int availKeys)
    {
        queue<pair<int,int>> q;
        q.push({sr, sc});
        grid[sr][sc] = '#';
        int level = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int r = q.front().first, c = q.front().second;
                q.pop();
                if(r == er && c == ec)
                {
                    return level;
                }   
                int dx[] = {-1, 0, 1, 0};
                int dy[] = {0, 1, 0, -1};
                for(int k=0;k<4;k++)
                {
                    int _r = r + dx[k], _c = c + dy[k];
                    if(_r >= 0 && _r < grid.size() && _c >= 0 && _c < grid[0].size())
                    {
                        if(grid[_r][_c] == '.' || (grid[_r][_c] >= 'a'  && grid[_r][_c] <= 'z') || grid[_r][_c] == '@')
                        {
                            q.push({_r, _c});
                            grid[_r][_c] = '#';
                        }
                        else if(grid[_r][_c] >= 'A' && grid[_r][_c] <= 'Z')
                        {
                            int keyno = grid[_r][_c] - 'A';
                            if((availKeys&(1<<keyno)))
                            {
                                q.push({_r, _c});
                                grid[_r][_c] = '#';
                            }
                        }
                    }
                }
            }
            level++;
        }

        return 1e9;
    }

    int solve(int sr,int sc,int avaiKeys,vector<vector<int>> &keys,vector<string> &grid)
    {
        if(avaiKeys + 1 == (1<<keys.size()))
        {
            return 0;
        }
        if(dp[sr][sc][avaiKeys] != -1)
        {
            return dp[sr][sc][avaiKeys];
        }
        int ans = 1e9;
        for(int i=0;i<keys.size();i++)
        {
            int keyno =  keys[i][0];
            if((avaiKeys&(1<<keyno)) == 0)
            {
                int temp =  getShoretestPathfromSrctoDest(grid, sr, sc, keys[i][1], keys[i][2], avaiKeys);
                int newAvailKeys = (avaiKeys|(1<<keyno));
                temp += solve(keys[i][1], keys[i][2], newAvailKeys, keys, grid);
                ans = min(ans, temp);
            }
        }
        return dp[sr][sc][avaiKeys] = ans;
    }

    int shortestPathAllKeys(vector<string>& grid) {
        int sr = 0, sc = 0;
        vector<vector<int>> keys;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] >= 'a' && grid[i][j] <= 'z')
                {
                    keys.push_back({grid[i][j]-'a',i,j});
                }
                else if(grid[i][j] == '@')
                {
                    sr = i, sc = j;
                }
            }
        }
        
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(sr,sc,0,keys,grid);
        if(ans == 1e9)
        {
            ans = -1;
        }
        return ans;
    }
};