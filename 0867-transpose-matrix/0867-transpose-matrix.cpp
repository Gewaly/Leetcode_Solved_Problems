class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>>ans(matrix[0].size(),vector<int>(matrix.size(),0));
        for(int i=0;i<matrix[0].size();i++){
            for(int j=0;j<matrix.size();j++){
                cout<<matrix[j][i]<<" ";
                ans[i][j]=matrix[j][i];
            }
        }
        return ans;
    }
};