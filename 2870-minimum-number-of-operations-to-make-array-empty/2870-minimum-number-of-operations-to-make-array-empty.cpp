class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)  mp[nums[i]]++;
        int cnt=0;
        for(auto x: mp){
           if(x.second==1)return -1;
             cnt+= x.second/3;
            if(x.second%3)cnt++;

        }
        return cnt;
        
        
    }
};