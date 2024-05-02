class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int>res=nums;
        sort(res.begin(),res.end());
      sort(nums.rbegin(),nums.rend());
        for(int i=0;i<nums.size();i++){
              cout<<nums[i]<<" ";
            int x=nums[i]*-1;
                      
            if(binary_search(res.begin(),res.end(),x)) return nums[i];
            
        }
        
        return -1;
    }
};