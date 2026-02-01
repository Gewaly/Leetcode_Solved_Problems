class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum=nums[0];
        vector<int>ans;
        for(int i=1;i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        sort(ans.begin(),ans.end());
        sum+=ans[0]; sum+=ans[1];
        return sum;
    }
};