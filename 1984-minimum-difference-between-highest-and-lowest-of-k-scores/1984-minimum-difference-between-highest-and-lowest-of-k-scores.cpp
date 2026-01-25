class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size()==1) return 0;
      sort(nums.begin(), nums.end());
        int mn=INT_MAX;
        for (int i=0; i+k-1<nums.size(); i++) {
            mn =min(mn, nums[i+k-1]-nums[i]);
        }

        return mn;
    }
    
};