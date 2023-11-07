class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long mul=1;
        vector<int>res(nums.size(),0);
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) cnt++;  
            else mul*=nums[i];
        }
        
        if(cnt==0){
        for(int i=0;i<nums.size();i++){
                    res[i]=mul/nums[i];
        }
        return res;
        }
        
        
        else if(cnt==1){
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) res[i]=0;
            else res[i]=mul;
              
        }
        }
        return res;
       
    }
};