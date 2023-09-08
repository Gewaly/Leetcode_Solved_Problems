class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0){
            return res;
        }
        res.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            int j=1;
            while(j<i){
                temp.push_back(res[i-1][j-1]+res[i-1][j]);
                j++;
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};