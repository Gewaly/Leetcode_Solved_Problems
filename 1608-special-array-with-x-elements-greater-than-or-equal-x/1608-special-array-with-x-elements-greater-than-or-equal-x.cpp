class Solution {
public:
    int specialArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi=* max_element(nums.begin(),nums.end());
        for(int x:nums){
            mp[x]++;
        }
        unordered_map<int,int>mp2;
        int cnt=0;
        for(int i=0;i<=maxi;i++){
            mp2[i]=nums.size()-cnt;
            cnt+=mp[i];
        }
        for(auto it:mp2){
            if(it.first==it.second)   return it.first;
        }
        return -1;
    }
};