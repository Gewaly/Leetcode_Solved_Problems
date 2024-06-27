class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int>mp;
        for(int i=0;i<edges.size();i++){
        for(int j=0;j<edges[i].size();j++){
            mp[edges[i][j]]++;        
         }
        }
        int max=-1,center;
        for(auto x: mp){
            if(x.second>max){
                center=x.first;
                max=x.second;
            }
        }
        return center;
    }
};