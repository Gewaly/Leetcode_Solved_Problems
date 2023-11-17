class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    int l=0;
    int r=nums.size()-1;
    int maxi=INT_MIN;
        while(l<r){
           int sum=nums[l]+nums[r];
            //cout<<nums[l]<<" "<<nums[r]<<endl;
           // cout<<sum<<endl;
            maxi=max(maxi,sum); l++;
         r--;
    }
        return maxi;
    }
};