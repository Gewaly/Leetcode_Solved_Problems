class Solution {
public:
    int dr[4] = {0, 0, -1, 1};
    int dc[4] = {-1, 1, 0, 0};
    bool isSafe(int i, int j, int n){
        return (i >= 0 && j >= 0 && i < n &&  j < n);
    }
    void dfs(queue<pair<int,int>> &q, vector<vector<int>>& grid, int &n){
        int level = 0;
        while(!q.empty()){
            int s = q.size();
            level++;
            while(s--){
                pair<int,int> temp = q.front();
                q.pop();
                for(int i = 0; i<4; ++i){
                    int x = temp.first + dr[i];
                    int y = temp.second + dc[i];
                    if(isSafe(x, y, n)){
                        if(grid[x][y] == 0){
                            grid[x][y] = level;
                            q.push({x, y});
                        }
                    }
                }
            }
        }
    }
    int dfss(priority_queue<pair<int,pair<int,int>>> &q, vector<vector<int>>& grid, int &n){
        int count = 0;
        while(!q.empty()){
            pair<int,pair<int, int>> top = q.top();
            q.pop();
            if(top.second.first == n-1 && top.second.second == n-1){
                return top.first;
            }
            for(int i = 0; i < 4; ++i){
                int x = top.second.first + dr[i];
                int y = top.second.second + dc[i];
                if(isSafe(x, y, n)){
                    if(grid[x][y] != -1){
                        int minm = min(top.first, grid[x][y]);
                        q.push({minm, {x, y}});
                        grid[x][y] = -1;
                    }
                }
            }
        }
        return -1;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = grid.size();
        queue<pair<int,int>> q;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    grid[i][j] = -1;
                }
            }
        }
        dfs(q, grid, n);
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                if(grid[i][j] == -1)
                    grid[i][j] = 0;
            }
        }
        priority_queue<pair<int,pair<int,int>>> qu;
        qu.push({grid[0][0], {0, 0}});
        grid[0][0] = -1;
        return dfss(qu, grid, n);
    }
};