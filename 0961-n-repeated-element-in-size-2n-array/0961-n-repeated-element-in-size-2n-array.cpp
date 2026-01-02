class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size()/2;
        for(auto x: nums){
            mp[x]++;
        }
        for(auto x:mp){
            if(x.second==n) return x.first;
        }
        return -1;
        
    }
};