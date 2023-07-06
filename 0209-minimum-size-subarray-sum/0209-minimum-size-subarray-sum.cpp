class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long sum_all=accumulate(nums.begin(),nums.end(),0);
        if(sum_all<target) return 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=target) return 1;
            }
        int l=0,r=0,sum=0,mn=INT_MAX;
        while(r<nums.size()){
            sum+=nums[r++];
            while(sum>=target){
                mn=min(mn,r-l);
                sum-=nums[l++];
            }   
        }
        return mn;
        
    }
};