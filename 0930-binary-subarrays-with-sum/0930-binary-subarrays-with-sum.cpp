class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int, int> mp;
        int ans=0,sum=0;
        mp[0]=1;
        for(auto i : nums){
            sum+=i;
            ans+=mp[sum-goal];
            mp[sum]++;
        }
        return ans;
    }
};