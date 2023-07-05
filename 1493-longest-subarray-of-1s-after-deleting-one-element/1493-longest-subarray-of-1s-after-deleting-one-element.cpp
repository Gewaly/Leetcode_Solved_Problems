class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int mx=0,cnt1=0,prev=-1;
        for(int i=0;i<nums.size();i++){
            if( nums[i]==1) cnt1++;
            else prev=cnt1,cnt1=0;
            mx=max(mx,cnt1+prev);
       }
    return mx;   
    }
};