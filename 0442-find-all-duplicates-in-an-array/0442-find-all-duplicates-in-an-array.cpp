class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int>mp;
        vector<int>res;
        for(auto x: nums){
            mp[x]++;
        }
        for(auto x: mp){
            if(x.second==2) res.push_back(x.first);
        }
        return res;
        
    }
};