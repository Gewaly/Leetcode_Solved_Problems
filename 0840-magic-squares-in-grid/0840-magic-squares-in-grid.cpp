class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3) {
            return 0;
        }
        int r=grid.size()-2;
        int c=grid[0].size()-2;
        int sum=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                bool isValid=true;
                vector<int> m={grid[i][j],grid[i][j+1],grid[i][j+2],
                               grid[i+1][j],grid[i+1][j+1],grid[i+1][j+2],
                               grid[i+2][j],grid[i+2][j+1],grid[i+2][j+2]};
                unordered_map<int,int> mp;
                for(int k=0;k<9;k++){
                    if(m[k]<1||m[k]>9){
                        isValid=false;
                        break;
                    }
                    mp[m[k]]++;
                    if(mp[m[k]]>1){
                        isValid=false;
                        break;
                    }     
                }
                if(!isValid) continue;
                int su=m[0]+m[1]+m[2];
                for(int k = 0; k < 9; k = k + 3) {
                    if((m[k] + m[k+1] + m[k+2]) != su){
                        isValid=false;
                        break;
                    } 
                }
                for(int k = 0; k < 3; k++) {
                    if((m[k] + m[k+3] + m[k+6]) != su){
                        isValid=false;
                        break;
                    }
                }
                if((m[0] + m[4] + m[8]) != su||(m[2] + m[4] + m[6]) != su){
                    isValid=false;
                }
                if(isValid){
                    sum++;
                }
            }
        }
        return sum;
    }
};