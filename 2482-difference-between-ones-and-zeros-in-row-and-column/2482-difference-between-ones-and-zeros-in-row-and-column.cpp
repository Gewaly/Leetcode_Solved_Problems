class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> ones_row(m, 0), ones_col(n, 0),zeros_row(m, 0),zeros_col(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) ones_row[i]++,  ones_col[j]++;
                 else zeros_row[i]++, zeros_col[j]++;
                
            }
        }
        vector<vector<int>> diff(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) 
                diff[i][j] = ones_row[i] + ones_col[j] - zeros_row[i] - zeros_col[j];
            
        }
        
        return diff;
    }
};