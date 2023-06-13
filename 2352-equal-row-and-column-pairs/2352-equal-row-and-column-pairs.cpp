class Solution {
public:
   string Mapfun(vector<int>&nums){
       string temp = "";
       for(auto it:nums){
           temp += to_string(it) + "$";
       } 
       cout<<temp<<endl;
       return temp;
   }
    int equalPairs(vector<vector<int>>& grid) {
      int ans=0;
      int n = grid.size();
      unordered_map<string,int>mp;
    
    
      for(int i=0;i<n;i++){
          mp[Mapfun(grid[i])]++;
      } 
       
       for(int i=0;i<n;i++){
           string search = "";
           for(int j=0;j<n;j++){
               search += to_string(grid[j][i]) + "$";
           }
          ans += mp[search];
       }
      return ans;
    }
};