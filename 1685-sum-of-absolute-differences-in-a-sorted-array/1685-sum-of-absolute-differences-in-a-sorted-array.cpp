class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        vector<int>ans;
        int i,c=0,s=0,n=nums.size();
        s = accumulate(nums.begin(),nums.end(),0);
        for(i=0;i<n;i++){
            int x = (nums[i]*(i)-c);
            int y = (s-c)-nums[i]*(n-i);
            ans.push_back(x+y); c+=nums[i];
        }
        return ans;
        
    }
};