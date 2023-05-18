class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> v(n,0),ans;
        for(auto &i: edges){
            v[i[1]]++;
        }
          for(auto &i: edges){
            cout<<i[1]<<" "<<v[i[1]]<<endl;
        }
        
        for(int i = 0; i < n; i++){
            if(!v[i]) ans.push_back(i);
        }
        return ans;
    
    }
};