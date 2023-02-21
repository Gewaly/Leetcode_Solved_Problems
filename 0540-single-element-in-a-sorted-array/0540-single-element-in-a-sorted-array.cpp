class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int,int>mpp;
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size()-1;i+=2){
          //  mpp[nums[i]]++;
            if(nums[i]!=nums[i+1]) return nums[i];
        }
        //for(auto x: mpp) {
          //  if(x.second==1) return x.first;
        //}
        return nums[nums.size()-1];
        
    }
};