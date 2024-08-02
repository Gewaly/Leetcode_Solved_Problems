class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ans=INT_MAX,cnt0=0,cnt1=0,n=nums.size();
        for(auto it:nums){
            if(it==1)
                cnt1++;
        }
        for(int i=0;i<cnt1;i++){
            if(nums[i]==0)
                cnt0++;
        }
        ans=min(cnt0,ans);
        for(int i=cnt1;i<2*n;i++){
            if(nums[i%n]==0)
                cnt0++;
            if(nums[(i-cnt1)%n]==0)
                cnt0--;
            ans=min(ans,cnt0);
        }
        return ans;
    }
};