class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>ump;
        vector<vector<int>>ans;
        for(int i=0;i<groupSizes.size();i++){
            ump[groupSizes[i]].push_back(i);
            if(ump[groupSizes[i]].size()==groupSizes[i]){
                ans.push_back(ump[groupSizes[i]]);
                ump[groupSizes[i]].clear();
            }
        }
        return ans;
        
    }
};