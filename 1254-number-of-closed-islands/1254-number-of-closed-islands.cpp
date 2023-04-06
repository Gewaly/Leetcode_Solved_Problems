class Solution {
    
private:
    bool isClosed(vector<vector<int>>& grid, int i, int j) {
       
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size())return false;
        
        if (grid[i][j] == 1 || grid[i][j] == 2) return true;

        grid[i][j] = 2;
        bool isLeftClosed = isClosed(grid, i, j - 1);
        bool isRightClosed = isClosed(grid, i, j + 1);
        bool isTopClosed = isClosed(grid, i + 1, j);
        bool isBottomClosed = isClosed(grid, i - 1, j);

        return isLeftClosed && isRightClosed && isTopClosed && isBottomClosed;
    }    
public:
     int closedIsland(vector<vector<int>>& grid) {
        int islands = 0;
        for(int i = 0; i < grid.size(); i++) { 
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 0 && isClosed(grid, i, j)) {
                    islands++;
                }
            }
        }
        return islands;
    }
};