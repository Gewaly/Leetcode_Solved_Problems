class Solution {
public:
    bool canJump(vector<int>& nums) {
    /*    
        int v=0;
        if(nums[0]==0&& nums.size()!=1) return false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                int cnt=1;
                for(int j=i-1;j>=0;j--){
                    if(nums[j]!=cnt||nums[j]<=cnt ){
                        return false;
                    }
                    else cnt++;
                    
                }
                
            }
        }
        return true;
        /*
        
    /*    stack<int>st;
           for(int i=0;i<nums.size();i++){
           st.push(nums[i]);
               
           
           
           }
        
      */  
        
        
        
        int n = nums.size();
        int reachable = 0;
        
        for(int i=0;i<n;++i)
        {
            if(reachable < i)
                return false;
            reachable = max(reachable,i+nums[i]);
        }
        return true;  
        
        
        
    }
        
        
};