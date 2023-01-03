class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      vector<int>res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0)
                 res.push_back(nums[i]);
                 } 
                 for(int i=res.size();i<n;i++){
                 res.push_back(0);
                 }
        
          nums=res;
                 for(auto x: nums) cout<<x<<" ";
    

                 
    }
};