class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> v(n * 3, vector<int>(n * 3, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    v[i * 3][j * 3 + 2] = 1;
                    v[i * 3 + 1][j * 3 + 1] = 1;
                    v[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    v[i * 3][j * 3] = 1;
                    v[i * 3 + 1][j * 3 + 1] = 1;
                    v[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
       
        
        int regions = 0;
        for (int i = 0; i < n * 3; i++) {
            for (int j = 0; j < n * 3; j++) {
                if (v[i][j] == 0) {  
                    dfs(v, i, j);
                    regions++;
                }
            }
        }
        
        return regions;
    }

private:
    void dfs(vector<vector<int>>& v, int i, int j) {
        int n = v.size();
        if (i < 0 || j < 0 || i >= n || j >= n || v[i][j] == 1) {
            return;
        }
        v[i][j] = 1; 
        dfs(v, i + 1, j); 
        dfs(v, i - 1, j); 
        dfs(v, i, j + 1); 
        dfs(v, i, j - 1); 
    }
};
