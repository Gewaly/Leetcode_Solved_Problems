class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
         if (mat.empty() || r * c != mat.size() * mat[0].size())
      return mat;

    vector<vector<int>> ans(r, vector<int>(c));
    int k = 0;

    for (const vector<int>& row : mat)
      for (const int num : row) {
        ans[k / c][k % c] = num;
        ++k;
      }

    return ans;
    }
};