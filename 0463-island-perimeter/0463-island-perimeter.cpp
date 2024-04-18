class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum = 0;
        for(int x=0; x<grid.size(); x++) {
            for(int i=0; i<grid[0].size(); i++) {
                if(grid[x][i] == 1) {
                    sum += 4;
                    if(0 <= x-1 && x-1 <grid.size() && grid[x-1][i] == 1) sum--;
                    if(0 <= x+1 && x+1 <grid.size() && grid[x+1][i] == 1) sum--;
                    if(0 <= i-1 && i-1 <grid[0].size() && grid[x][i-1] == 1) sum--;
                    if(0 <= i+1 && i+1 <grid[0].size() && grid[x][i+1] == 1) sum--;
                }
            }
        }
        return sum;
    }
};