class Solution {
public:
    int drow[4] = {0,-1,0,1};
    int dcol[4] = {-1,0,1,0}; 
    bool possible(vector<vector<int>>& grid, int i, int j, int row, int col,vector<vector<int>>& visited){
        visited[i][j] = 1;
        if(i==row-1){
            return true;
        }
        bool ans = false;
        for(int h = 0;h<4;h++){
            if(i+drow[h]>=0 && i+drow[h]<row && j+dcol[h]>=0 && j+dcol[h]<col && visited[i+drow[h]][j+dcol[h]]==0 && grid[i+drow[h]][j+dcol[h]]!=1){
                bool curr = possible(grid,i+drow[h],j+dcol[h],row,col,visited);
                ans = ans | curr;
            }
        }
        return ans;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> visited(row,vector<int>(col,0));
        int days = cells.size();
        int ans = 0;
        int hi = days-1;
        int lo = 0;

        while(lo<=hi){
            int mid = (lo+hi)/2;
            vector<vector<int>> grid(row,vector<int>(col,0));
            for(int i = 0;i<=mid;i++){
               auto curr = cells[i];
               grid[curr[0]-1][curr[1]-1] = 1;
            }
            vector<vector<int>> visited(row,vector<int>(col,0));
            bool temp = false;
            for(int j = 0;j<col;j++){
                if(grid[0][j]==0 && visited[0][j]==0){
                    temp = temp | possible(grid,0,j,row,col,visited);
                    if(temp==true){
                        ans = mid;
                        break;
                    }
                }
            }
            if(temp==false){
               hi = mid-1;
            }
            if(temp==true){
               lo = mid+1;
            }
        }
        return ans+1;
    }
};