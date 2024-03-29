class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int i,j,maxi=INT_MIN,n=nums.size();
        long long ans=0;
        for(i=0;i<n;i++){
            maxi=max(nums[i],maxi);
        }
        i=j=0;
        while(j<n){
            if(nums[j]==maxi){
                k--;
            }
            while(k==0){
                ans=ans+(n-j);
                if(nums[i]==maxi){
                    k++;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};